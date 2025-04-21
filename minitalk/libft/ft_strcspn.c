/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:54:15 by manualva          #+#    #+#             */
/*   Updated: 2024/08/06 12:03:03 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t		i;
	const char	*r;

	i = 0;
	while (s[i])
	{
		r = reject;
		while (*r)
		{
			if (s[i] == *r)
			{
				return (i);
			}
			r++;
		}
		i++;
	}
	return (i);
}
