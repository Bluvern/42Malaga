/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:05 by manualva          #+#    #+#             */
/*   Updated: 2023/11/04 10:43:01 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	n;

	n = 0;
	while (src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

/*int main (void)
{
	char str1[5] = "str1";
	char str2[5] = "str2";

	ft_strcpy	(str1, str2);
	printf ("%s, %s\n", str1, str2);
	return (0);
}*/
