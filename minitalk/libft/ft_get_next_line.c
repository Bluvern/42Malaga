/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:41:55 by manualva          #+#    #+#             */
/*   Updated: 2024/08/06 10:34:46 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_buffer(char *result, char *content)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!result || !content)
		return (NULL);
	new = ft_calloc(ft_strlen(result) + ft_strlen(content) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (result[i])
	{
		new[i] = result[i];
		i++;
	}
	while (content[j])
	{
		new[i + j] = content[j];
		j++;
	}
	new[i + j] = '\0';
	free(result);
	return (new);
}

static char	*find_next_line(char *content)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
		return (free(content), NULL);
	line = ft_calloc(ft_strlen(content) - i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i++;
	while (content[i])
		line[j++] = content[i++];
	free(content);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}

static char	*get_line(char *content)
{
	int		i;
	char	*line;

	i = 0;
	if (!content || content[i] == '\0')
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	if (content[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_file(int fd, char *result)
{
	char	*content;
	int		num_bytes;

	if (!result)
		result = ft_calloc(1, sizeof(char));
	if (!result)
		return (NULL);
	content = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!content)
		return (NULL);
	num_bytes = read(fd, content, BUFFER_SIZE);
	while (num_bytes > 0)
	{
		content[num_bytes] = '\0';
		result = free_buffer(result, content);
		if (ft_strchr(content, '\n'))
			break ;
		num_bytes = read(fd, content, BUFFER_SIZE);
	}
	free(content);
	if (num_bytes < 0)
		return (free(result), NULL);
	return (result);
}

char	*ft_get_next_line(int fd)
{
	static char	*content[MAX_FILES];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content[fd] = read_file(fd, content[fd]);
	if (!content[fd])
		return (NULL);
	line = get_line(content[fd]);
	content[fd] = find_next_line(content[fd]);
	return (line);
}
