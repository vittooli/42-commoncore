/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:47:05 by volivier          #+#    #+#             */
/*   Updated: 2024/02/09 15:42:14 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update(char *s1, char *s2)
{
	char	*ret;

	if (s1 != NULL && s2 == NULL)
	{
		ret = ft_strdup(s1);
		free(s1);
		return (ret);
	}
	if (s1 == NULL && s2 != NULL)
	{
		ret = ft_strdup(s2);
		free(s2);
		return (ret);
	}
	if (!s1)
		return (NULL);
	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}

char	*ft_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i])
	{
		line[i] = buff[i];
		if (buff[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd)
{
	char	*ret;
	char	*buff;
	int		bytes_read;

	bytes_read = 1;
	ret = NULL;
	while (bytes_read > 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (!bytes_read)
		{
			free (buff);
			break ;
		}
		buff[bytes_read] = '\0';
		ret = ft_update(ret, buff);
		if (ft_strchr(ret, '\n'))
			break ;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buff;

	line = NULL;
	buff = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (save != NULL)
		buff = ft_update(save, ft_read(fd));
	else
		buff = ft_read(fd);
	if (!buff)
		return (NULL);
	line = ft_line(buff);
	if (*line == '\0')
	{
		free (line);
		free (buff);
		return (NULL);
	}
	save = ft_strdup(buff + ft_strlen(line));
	free(buff);
	return (line);
}
