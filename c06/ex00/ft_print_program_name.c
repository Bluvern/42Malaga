/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:35:26 by manualva          #+#    #+#             */
/*   Updated: 2023/11/15 11:41:26 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	n;

	n = 0;
	if (argc > 0)
	{
		while (argv[0][n] != '\0')
		{
			ft_putchar (argv[0][n]);
			n++;
		}
		write (1, "\n", 1);
	}
	return (0);
}
