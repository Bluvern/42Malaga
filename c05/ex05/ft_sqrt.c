/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:31:49 by manualva          #+#    #+#             */
/*   Updated: 2023/11/14 15:31:27 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	if (nb == 0)
		return (0);
	while ((n * n) < nb)
		n++;
	if ((n * n) == nb)
		return (n);
	else
		return (0);
}
/*
int main (void)
{
	printf("%d\n", ft_sqrt(-1));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(5));
	printf("%d\n", ft_sqrt(81));
}
*/