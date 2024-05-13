/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:15:21 by manualva          #+#    #+#             */
/*   Updated: 2023/11/04 16:15:36 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	ch;
	int	n;

	ch = 1;
	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] < 'A' || str[n] > 'Z')
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
	printf ("%d", ft_str_is_uppercase("minusculas"));
	printf ("%d", ft_str_is_uppercase("MAYUSCULAS"));
	printf ("%d", ft_str_is_uppercase("69420"));
	printf ("%d", ft_str_is_uppercase("MinusculasYMayusculas"));
	printf ("%d", ft_str_is_uppercase("L3tr45YNum3r05"));
	printf ("%d", ft_str_is_uppercase("Con Espacios"));
	printf ("%d", ft_str_is_uppercase("Caracteres extraños"));
	printf ("%d", ft_str_is_uppercase(""));
}
*/