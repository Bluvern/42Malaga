/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:20:52 by manualva          #+#    #+#             */
/*   Updated: 2024/05/10 10:39:31 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	size;

	size = 0;
	if (str == 0)
	{
		return (ft_print_string("(null)"));
	}
	while (str[size])
	{
		size += ft_print_char(str[size]);
	}
	return (size);
}
