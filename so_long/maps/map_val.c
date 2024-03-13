#include "maps.h"

char	*f_to_str(char *path) //prende il file contente la mappa e la rende in una stringa
{
	int		fd;
	char	*ret;
	char	buff[BUFFER_SIZE + 1];
	char 	*tofree;
	
	fd = open(path, O_RDONLY);
	buff[BUFFER_SIZE] = 0;
	ret = ft_strdup("");
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		tofree = ret;
		ret = ft_strjoin(ret, buff);
		free(tofree);
	}
	close(fd);
	return (ret);
}

int	map_rec(char **matrix)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(matrix[0]);
	while (matrix[i])
	{
		if (ft_strlen(matrix[i]) != len)
			return (1);
		i++;
		len = ft_strlen(matrix[i]);
	}
	return (0);
}

int map_flags(t_map *map, int x, int y)
{
	if (map->mat[y][x] != '1' && map->mat[y][x] != '0' && map->mat[y][x] != 'E' && map->mat[y][x] != 'P' && map->mat[y][x] != 'C')
		return (1);
	if (map->mat[y][x] == 'E')
		map->E++;
	else if (map->mat[y][x] == 'P')
		map->P++;
	else if (map->mat[y][x] == 'C')
		map->C++;
}


int	map_char(t_map *map, int nb_lines)
{
	int	y;
	int x;

	y = 0;
	x = 0;
	while (y < nb_lines)
	{
		x = 0;
		while (x < ft_strlen(map->mat[0]))
		{
			if ((y == 0 || y == nb_lines || x == 0 || x == (ft_strlen(map->mat[0]) - 1)) && map->mat[y][x] != 1)
				return (1);
			else
				map_flags(map, x, y);
			x++;
		}
		y++;
	}
	if (map->E != 1 || map->P != 1 || map->C < 1)
		return(1);
	return (0);
}

t_point	find_start(t_map *map, int nb_lines)
{
	t_point p;

	p.x = 0;
	while (p.x < ft_strlen(map->mat[0]))
	{
		p.y = 0;
		while (p.y < nb_lines)
		{
			if (map->mat[p.y][p.x] == 'P')
				break ;
			p.y++;
		}
		p.x++;
	}
	return (p);
}

int	flood_fill(t_map *map, t_point p, int nb_lines)
{
	int x;
	int y;

	map->mat[p.y][p.x] = '-';
	if (map->mat[p.y + 1][p.x] != 1)
		p.y += 1;
	else if(map->mat[p.y][p.x + 1] != 1)
		p.x += 1;
	else if (map->mat[p.y - 1][p.x] != 1)
		p.y -= 1;
	else if (map->mat[p.y][p.x - 1] != 1)
		p.x -= 1;
	flood_fill(map, p, nb_lines);
	x = 0;
	while (x++ < ft_strlen(map->mat[0]))
	{
		y = 0;
		while (y++ < nb_lines)
			map_flags(map, x, y);
	}
	if (map->P != 0 || map->C != 0 || map->E != 0)
		return (1);
	return (0);
}

int	map_fill(t_map *map, t_point start, int nb_lines)
{
	t_map	*copy;
	int 	i;
	int		flag;

	copy->mat = ft_calloc(sizeof(char *), nb_lines);
	if (copy->mat == NULL)
		return (1);
	i = 0;
	while (i < nb_lines)
	{
		copy->mat[i] = ft_strdup(map->mat[i]);
		i++;
	}
	flag = flood_fill(copy, start, nb_lines);
	free(copy->mat);
	if (flag == 1)
		return (1);
	return (0);
}


/* funzione per il controllo della  mappa data in fd
chiama funzioni per:
- trasformare il file da "mappa" a stringa
- trasforare la stringa in matrice (con split)
- controlli vari:
	- mappa rettangolare
	- mappa contiene solo P E C 0 1 
	- mappa percorribile */

int	map_val(t_map *map)
{
	int		fd;
	char	*map_str;
	int		nb_lines;
	t_point	start;

	nb_lines = 0;
	map_str = f_to_str(map -> path);
	map->mat = ft_split(map_str, '\n');

	while(map->mat++ != 0)
		printf("mappa: %s", map->(char *)mat++);

	while (*map->mat++)
		nb_lines++;
	if (map_rec(map->mat) == 1)
		return (1);
	if (map_char(map, nb_lines) == 1)
		return (1);
	start = find_start(map, nb_lines);
	if (map_fill(map, start, nb_lines) == 1)
		return (1);
	return (0);
}