/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:17:28 by manualva          #+#    #+#             */
/*   Updated: 2023/11/04 16:17:30 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	ch;
	int	n;

	ch = 1;
	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] < ' ' || str[n] > '~')
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
	printf ("%d", ft_str_is_printable("minusculas"));
	printf ("%d", ft_str_is_printable("MAYUSCULAS"));
	printf ("%d", ft_str_is_printable("69420"));
	printf ("%d", ft_str_is_printable("MinusculasYMayusculas"));
	printf ("%d", ft_str_is_printable("L3tr45YNum3r05"));
	printf ("%d", ft_str_is_printable("Con Espacios"));
	printf ("%d", ft_str_is_printable("Caracteres extraños"));
	printf ("%d", ft_str_is_printable(""));
}
*/