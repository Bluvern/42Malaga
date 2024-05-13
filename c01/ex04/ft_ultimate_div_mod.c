/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:24:51 by manualva          #+#    #+#             */
/*   Updated: 2023/11/02 11:59:19 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*int	main(void)
{
	int	n1;
	int	n2;

	n1 = 7;
	n2 = 2;
	ft_ultimate_div_mod(&n1, &n2);
	printf("cociente %d, resto %d\n", n1, n2);
	return (0);
}*/
