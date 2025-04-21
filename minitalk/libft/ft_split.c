/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:51:02 by manualva          #+#    #+#             */
/*   Updated: 2024/04/29 14:01:28 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char limit)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != limit)
		{
			if (!is_word)
			{
				is_word = 1;
				count++;
			}
		}
		else
			is_word = 0;
		s++;
	}
	return (count);
}

static char	*copy_word(const char *s, char limit)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	i = 0;
	while (s[len] && s[len] != limit)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_split(char **split)
{
	char	**ptr;

	ptr = split;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;
	int		i;

	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = copy_word(s, c);
			if (result[i] == NULL)
				return (free_split(result), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[word_count] = NULL;
	return (result);
}
