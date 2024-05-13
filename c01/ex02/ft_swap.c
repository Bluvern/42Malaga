/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:03:56 by manualva          #+#    #+#             */
/*   Updated: 2023/11/02 11:59:17 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	swapa;
	int	swapb;

	swapa = *a;
	swapb = *b;
	*a = swapb;
	*b = swapa;
}

/*int	main(void)
{
	int	n1;
	int	n2;

	n1 = 1;
	n2 = 3;
	printf("antes: %d, %d\n", n1, n2);
	ft_swap(&n1, &n2);
	printf("despues: %d, %d\n", n1, n2);
	return (0);
}*/
