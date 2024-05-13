/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:48:48 by manualva          #+#    #+#             */
/*   Updated: 2023/11/14 10:44:42 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	fact;

	n = 0;
	fact = 1;
	if (nb < 0)
		return (0);
	while (++n <= nb)
	{
		fact *= n;
	}
	return (fact);
}
/*
int main (void)
{
	printf("%d\n", ft_iterative_factorial(5));
}
*/