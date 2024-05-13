/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:12:21 by manualva          #+#    #+#             */
/*   Updated: 2023/11/11 14:33:54 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}
/*
int main (void)
{
	char *c = "lemao";

	printf("caracteres en '%s': %d\n", c, ft_strlen(c));
}
*/