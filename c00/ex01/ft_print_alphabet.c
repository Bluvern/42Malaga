/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:35:45 by manualva          #+#    #+#             */
/*   Updated: 2023/10/30 17:02:51 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	l;

	l = 'a';
	while (l <= 'z')
	{
		ft_putchar(l);
		l++;
	}
}

/*int	main(void)
{
	ft_print_alphabet();
	return (0);
}*/
