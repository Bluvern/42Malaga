/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_lowercase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:12:30 by manualva          #+#    #+#             */
/*   Updated: 2023/11/04 16:12:32 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	ch;
	int	n;

	ch = 1;
	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] < 'a' || str[n] > 'z')
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
	printf ("%d", ft_str_is_lowercase("minusculas"));
	printf ("%d", ft_str_is_lowercase("MAYUSCULAS"));
	printf ("%d", ft_str_is_lowercase("69420"));
	printf ("%d", ft_str_is_lowercase("MinusculasYMayusculas"));
	printf ("%d", ft_str_is_lowercase("L3tr45YNum3r05"));
	printf ("%d", ft_str_is_lowercase("Con Espacios"));
	printf ("%d", ft_str_is_lowercase("Caracteres extraños"));
	printf ("%d", ft_str_is_lowercase(""));
}
*/