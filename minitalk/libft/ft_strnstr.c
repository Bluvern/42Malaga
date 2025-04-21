/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:04:39 by manualva          #+#    #+#             */
/*   Updated: 2024/04/19 15:15:02 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[a] && a < len)
	{
		b = 0;
		while (haystack [a + b] == needle [b] && haystack [a + b])
		{
			b++;
			if (needle [b] == '\0' && (a + b) <= len)
				return ((char *)&haystack[a]);
		}
		a++;
	}
	return (NULL);
}
