/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:09:50 by manualva          #+#    #+#             */
/*   Updated: 2023/11/15 13:25:17 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	a = 1;
	if (argc > 1)
	{
		while (a < argc)
		{
			b = 0;
			while (argv[a][b] != '\0')
			{
				ft_putchar(argv[a][b]);
				b++;
			}
			write (1, "\n", 1);
			a++;
		}
	}
	return (0);
}
