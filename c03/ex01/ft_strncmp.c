/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:02:07 by manualva          #+#    #+#             */
/*   Updated: 2023/11/06 15:10:53 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (i < (n - 1)) && s1[i])
		i++;
	return (s1[i] - s2 [i]);
}
/*
int main (void)
{
	char *c1 = "lmao";
	char *c2 = "lmaO";
	unsigned int i = 3;

	printf("%d\n", ft_strncmp(c1, c2, i));
}
*/
