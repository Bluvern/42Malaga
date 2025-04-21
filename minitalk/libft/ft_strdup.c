/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:37:27 by manualva          #+#    #+#             */
/*   Updated: 2024/04/23 12:06:53 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(s1);
	dup = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (dup == NULL)
		return (NULL);
	while (i <= len)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
