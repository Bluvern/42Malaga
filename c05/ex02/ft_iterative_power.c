/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:09 by manualva          #+#    #+#             */
/*   Updated: 2023/11/14 10:44:41 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	n;
	int	i;

	n = nb;
	i = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (++i <= power)
	{
		nb *= n;
	}
	return (nb);
}
/*
int main (void)
{
	printf("%d\n", ft_iterative_power(2, 3));
}
*/