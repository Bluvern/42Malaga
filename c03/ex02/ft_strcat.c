/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:27:26 by manualva          #+#    #+#             */
/*   Updated: 2023/11/06 15:10:57 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	n1;
	int	n2;

	n1 = 0;
	n2 = 0;
	while (dest[n1] != '\0')
		n1++;
	while (src[n2] != '\0')
	{
		dest[n1] = src[n2];
		n1++;
		n2++;
	}
	dest[n1] = 0;
	return (dest);
}
/*
int main (void)
{
	char c1[8] = "lmao";
	char *c2 = "LMAO";

	printf("%s\n", ft_strcat(c1, c2));
}
*/