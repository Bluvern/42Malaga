/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:18:27 by manualva          #+#    #+#             */
/*   Updated: 2023/11/12 09:51:14 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_number(int n1, int n2, int n[])
{
	if (n1 >= 10)
	{
		n[0] = n1 / 10;
		n[1] = n1 - 10 * n[0];
	}
	else
	{
		n[0] = 0;
		n[1] = n1;
	}
	if (n2 >= 10)
	{
		n[2] = n2 / 10;
		n[3] = n2 - 10 * n[2];
	}
	else
	{
		n[2] = 0;
		n[3] = n2;
	}
}

void	ft_putchar_multi(int n1, int n2)
{
	int	n[4];

	ft_number (n1, n2, n);
	ft_putchar (n[0] + 48);
	ft_putchar (n[1] + 48);
	ft_putchar (' ');
	ft_putchar (n[2] + 48);
	ft_putchar (n[3] + 48);
	if (n1 != 98 || n2 != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putchar_multi (a, b);
			b++;
		}
		a++;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/