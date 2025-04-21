/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:02:09 by manualva          #+#    #+#             */
/*   Updated: 2024/04/18 19:17:59 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				ch;

	str = s;
	ch = (unsigned char)c;
	while (n-- != 0)
	{
		if (*str == ch)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
