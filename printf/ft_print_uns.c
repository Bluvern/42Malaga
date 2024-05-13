/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:20:55 by manualva          #+#    #+#             */
/*   Updated: 2024/05/10 13:06:19 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
	{
		size += ft_print_char('0');
		return (size);
	}
	if (n / 10)
		size += ft_print_unsigned(n / 10);
	size += ft_print_char('0' + n % 10);
	return (size);
}
