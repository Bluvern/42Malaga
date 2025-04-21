/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:20:42 by manualva          #+#    #+#             */
/*   Updated: 2024/08/06 10:03:27 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_number(int n)
{
	int	size;

	size = 0;
	if (n == INT_MIN)
	{
		size += ft_print_string("-2147483648");
		return (size);
	}
	if (n < 0)
	{
		size += ft_print_char ('-');
		n *= -1;
	}
	if (n / 10)
		size += ft_print_number(n / 10);
	size += ft_print_char('0' + n % 10);
	return (size);
}
