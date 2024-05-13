/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:59:46 by manualva          #+#    #+#             */
/*   Updated: 2023/11/07 11:40:41 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	n1;
	unsigned int	n2;

	n1 = 0;
	n2 = 0;
	while (dest[n1] != '\0')
		n1++;
	while ((src[n2] != '\0') && (n2 < nb))
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
	char c1[9] = "lmao";
	char *c2 = "LMAO";
	unsigned int i = 7;

	printf("%s\n", ft_strncat(c1, c2, i));
}
*/