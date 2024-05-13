/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:47:59 by manualva          #+#    #+#             */
/*   Updated: 2023/11/04 15:48:02 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	ch;
	int	n;

	ch = 1;
	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] < '0' || str[n] > '9')
		{
			ch = 0;
		}
		n++;
	}
	return (ch);
}
/*
int main(void)
{
	printf ("%d", ft_str_is_numeric("minusculas"));
	printf ("%d", ft_str_is_numeric("MAYUSCULAS"));
	printf ("%d", ft_str_is_numeric("69420"));
	printf ("%d", ft_str_is_numeric("MinusculasYMayusculas"));
	printf ("%d", ft_str_is_numeric("L3tr45YNum3r05"));
	printf ("%d", ft_str_is_numeric("Con Espacios"));
	printf ("%d", ft_str_is_numeric("Caracteres extraños"));
	printf ("%d", ft_str_is_numeric(""));
}
*/