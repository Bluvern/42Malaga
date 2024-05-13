/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:48:16 by manualva          #+#    #+#             */
/*   Updated: 2023/11/05 10:48:21 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		while (str[n] >= 'A' && str[n] <= 'Z')
		{
			str[n] += 32;
			n++;
		}
		n++;
	}
	return (str);
}
/*
int main(void)
{
	char str1[] = "LMAO";
	ft_strlowcase(str1);
	printf ("%s", str1);
	return (0);
}
*/