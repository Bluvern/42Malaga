/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:19:04 by manualva          #+#    #+#             */
/*   Updated: 2023/11/02 11:59:15 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	n1;
	int	n2;
	int	d;
	int	r;

	n1 = 7;
	n2 = 2;
	ft_div_mod(n1, n2, &d, &r);
	printf("cociente %d, resto %d\n", n1, n2);
	return (0);
}*/
