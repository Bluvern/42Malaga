/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:33:22 by manualva          #+#    #+#             */
/*   Updated: 2023/11/12 10:09:27 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int n;
	int s;

	n = 0;
	while (n < (s / 2))
	{
		s = tab[n];
		tab[n] = tab[size - 1 - n];
		tab[size - 1 - n] = s;
		n++;
	}
	return (tab);
}

int main (void)
{
	int i = 12345;
	int s = 5;

	printf("%d\n", ft_rev_int_tab(i, s));
}
