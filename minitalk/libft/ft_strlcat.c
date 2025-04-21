/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:32:11 by manualva          #+#    #+#             */
/*   Updated: 2024/04/16 11:58:55 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	len;
	size_t	i;

	srclen = 0;
	dstlen = 0;
	i = 0;
	while (dst[dstlen] != '\0' && dstlen < dstsize)
		dstlen++;
	while (src[srclen] != '\0')
		srclen++;
	len = srclen + dstlen;
	while (src[i] != '\0' && (dstlen + 1) < dstsize)
		dst[dstlen++] = src[i++];
	if (dstlen < dstsize)
		dst[dstlen] = '\0';
	return (len);
}
