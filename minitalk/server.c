/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:26:46 by manualva          #+#    #+#             */
/*   Updated: 2024/08/08 15:54:38 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "libft/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char				message[BUFFER_SIZE];
	static int				bit_count;
	static unsigned char	current_char;
	static int				byte_index;

	(void) info;
	(void) context;
	if (sig == SIGUSR1)
		current_char |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		message[byte_index++] = current_char;
		current_char = 0;
		bit_count = 0;
		if (message[byte_index - 1] == '\0' || byte_index >= BUFFER_SIZE - 1)
		{
			message[byte_index] = '\0';
			ft_printf("Received message: %s\n", message);
			byte_index = 0;
			ft_memset(message, 0, BUFFER_SIZE);
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
