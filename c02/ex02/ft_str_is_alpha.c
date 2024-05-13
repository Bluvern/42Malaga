/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:24:07 by manualva          #+#    #+#             */
/*   Updated: 2023/11/04 14:47:30 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	ch;
	int	n;

	ch = 1;
	n = 0;
	while (str[n] != '\0')
	{
		if ((str[n] < 'A' || str[n] > 'Z') && (str[n] < 'a' || str[n] > 'z'))
		{
			ch = 0;
		}
		n++;
	}
	return (ch);
}

int main(void)
{
	printf ("%d", ft_str_is_alpha("minusculas"));
	printf ("%d", ft_str_is_alpha("MAYUSCULAS"));
	printf ("%d", ft_str_is_alpha("69420"));
	printf ("%d", ft_str_is_alpha("MinusculasYMayusculas"));
	printf ("%d", ft_str_is_alpha("L3tr45YNum3r05"));
	printf ("%d", ft_str_is_alpha("Con Espacios"));
	printf ("%d", ft_str_is_alpha("Caracteres extraños"));
	printf ("%d", ft_str_is_alpha(""));
}
