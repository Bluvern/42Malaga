/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:20:57 by manualva          #+#    #+#             */
/*   Updated: 2024/08/06 10:03:27 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length_hexa(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	if (len == 0)
		len = 1;
	return (len);
}

static void	search_hexa(unsigned int n, const char letter)
{
	if (n >= 16)
	{
		search_hexa (n / 16, letter);
		search_hexa (n % 16, letter);
	}
	else
	{
		if (n < 10)
			ft_print_char(n + '0');
		else
		{
			if (letter == 'x')
				ft_print_char(n - 10 + 'a');
			else if (letter == 'X')
				ft_print_char(n - 10 + 'A');
		}
	}
}

int	ft_print_hexa(unsigned int n, const char letter)
{
	if (n == 0)
		return (ft_print_char('0'));
	else
		search_hexa(n, letter);
	return (length_hexa(n));
}
