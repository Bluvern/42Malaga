/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:22:25 by manualva          #+#    #+#             */
/*   Updated: 2024/04/23 12:19:26 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		if (n == -2147483648)
			n = -(n - 1);
		n *= -1;
	}
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	convert_to_char(char *str, int n, int digits)
{
	if (n < 0)
	{
		*str++ = '-';
		if (n == -2147483648)
		{
			*str++ = '2';
			n = -(n % 1000000000);
			digits--;
		}
		else
			n *= -1;
		digits--;
	}
	if (n >= 10)
		convert_to_char(str, n / 10, digits - 1);
	*(str + digits - 1) = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	int		converted_digits;
	char	*str;

	if (n == -2147483648)
		converted_digits = 11;
	else
		converted_digits = count_digits(n);
	str = (char *)malloc((converted_digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	convert_to_char(str, n, converted_digits);
	*(str + converted_digits) = '\0';
	return (str);
}
