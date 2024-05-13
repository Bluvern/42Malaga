/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:32:11 by manualva          #+#    #+#             */
/*   Updated: 2024/04/16 11:18:21 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	cpy;

	srclen = 0;
	cpy = 0;
	while (src[srclen] != '\0')
		srclen++;
	while (dstsize > 1 && *src != '\0')
	{
		*dst++ = *src++;
		cpy++;
		dstsize--;
	}
	if (dstsize > 0)
		*dst = '\0';
	return (srclen);
}
