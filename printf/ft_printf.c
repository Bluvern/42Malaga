/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:27:33 by manualva          #+#    #+#             */
/*   Updated: 2024/05/10 13:04:41 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int ch)
{
	write (1, &ch, 1);
	return (1);
}

static int	choose_letter(va_list arg, const char letter)
{
	int	size;

	size = 0;
	if (letter == 'c')
		size += ft_print_char(va_arg(arg, int));
	else if (letter == 's')
		size += ft_print_string(va_arg(arg, char *));
	else if (letter == 'p')
		size += ft_print_pointer(va_arg(arg, unsigned long long));
	else if (letter == 'd' || letter == 'i')
		size += ft_print_number(va_arg(arg, int));
	else if (letter == 'u')
		size += ft_print_unsigned(va_arg(arg, unsigned int));
	else if (letter == 'x' || letter == 'X')
		size += ft_print_hexa(va_arg(arg, unsigned int), letter);
	else if (letter == '%')
		size += ft_print_char('%');
	return (size);
}

int	ft_printf(char const *str, ...)
{
	int		size;
	int		i;
	va_list	arg;

	size = 0;
	i = 0;
	va_start (arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += choose_letter(arg, str[i + 1]);
			i++;
		}
		else
			size += ft_print_char(str[i]);
		i++;
	}
	va_end (arg);
	return (size);
}
