/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:10:37 by manualva          #+#    #+#             */
/*   Updated: 2024/08/08 15:54:14 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "libft/libft.h"

void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

void	send_message(pid_t pid, const char *message)
{
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char *argv[])
{
	pid_t		server_pid;
	const char	*message;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server-pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	send_message(server_pid, message);
	return (0);
}
