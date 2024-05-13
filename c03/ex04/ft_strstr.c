/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:21:10 by manualva          #+#    #+#             */
/*   Updated: 2023/11/07 11:39:12 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	n;
	int	t;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			n = 0;
			t = 0;
			while (to_find[n] != '\0')
			{
				if (str[n] != to_find[n])
					t = 1;
				n++;
			}
			if (t == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
/*
int main (void)
{
	char *c1 = "mira mama salgo en la tele";
	char *c2 = "salgo";

	printf("%s\n", ft_strstr(c1, c2));
}
*/