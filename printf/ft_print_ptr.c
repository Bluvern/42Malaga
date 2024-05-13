/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:20:46 by manualva          #+#    #+#             */
/*   Updated: 2024/05/10 12:32:52 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	length_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	if (len == 0)
		len = 1;
	return (len);
}

static void	search_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		search_pointer(ptr / 16);
		search_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_print_char(ptr + '0');
		else
			ft_print_char(ptr - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	size;

	size = 0;
	size += ft_print_string("0x");
	if (ptr == 0)
		size += ft_print_char('0');
	else
	{
		search_pointer(ptr);
		size += length_pointer(ptr);
	}
	return (size);
}
