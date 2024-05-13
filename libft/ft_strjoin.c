/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:59:51 by manualva          #+#    #+#             */
/*   Updated: 2024/04/24 15:10:56 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;
	size_t	remaining;
	size_t	copied;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(len_s1 + len_s2 + 1);
	if (result == 0)
		return (0);
	remaining = (len_s1 + len_s2 + 1);
	copied = ft_strlcpy(result, s1, remaining);
	ft_strlcat(result + copied, s2, remaining - copied);
	return (result);
}
