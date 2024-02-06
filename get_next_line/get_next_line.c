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

char	*ft_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
		{
			line[i] = save[i];
			i++;
			break ;
		}
		line[i] = save[i];
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
	static char	*save = NULL;
	char		*line = NULL;
	char		*buff = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = ft_read(fd); //legge il BUFFER_SIZE (in buff ci sta tutta la riga che comprende nl)
	if (!buff)
		return (NULL);
	line = ft_line(buff); //restituisce line (a partire da buff)
	printf("line: %s\n", line);
	save = ft_strdup(buff + ft_strlen(line)); //
	printf("save: %s\n", save);
	free(buff);
	return (line);
}