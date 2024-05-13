/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:46:22 by manualva          #+#    #+#             */
/*   Updated: 2023/11/04 16:47:15 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		while (str[n] >= 'a' && str[n] <= 'z')
		{
			str[n] -= 32;
			n++;
		}
		n++;
	}
	return (str);
}
/*
int main(void)
{
	char str1[] = "lmao";
	ft_strupcase(str1);
	printf ("%s", str1);
	return (0);
}
*/