#include "../so_long.h"

int	map_rec(char **matrix)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(matrix[0]);
	while (matrix[i] != 0)
	{
		if (ft_strlen(matrix[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

int	map_char(t_map *map)
{
	int	y;
	int x;

	map->E = 0;
	map->C = 0;
	map->P = 0;
	y = -1;
	while (++y < map->nb_rows)
	{
		x = -1;
		while (++x < map->nb_cols)
		{
			//printf("%d, %d, %c\n", y, x, map->mat[y][x]);
			if ((y == 0 || y == (map->nb_rows - 1) || x == 0 || x == (ft_strlen(map->mat[0]) - 1)) && map->mat[y][x] != '1')
				return (1);
			if (map_flags(map, x, y) == 1)
				return (1);
		}
	}
	if (map->E != 1 || map->P != 1 || map->C < 1)
		return(1);
	return (0);
}

t_point	find_start(t_map *map)
{
	t_point p;

	p.x = -1;
	while (++p.x < map->nb_cols)
	{
		p.y = -1;
		while (++p.y < map->nb_rows)
		{
			if (map->mat[p.y][p.x] == 'P')
				return (p);
		}
	}
	return (p);
}
int	map_fill(t_map *map, t_point start)
{
	char	**copy;
	int 	i;
	int 	flag;

	copy = ft_calloc(sizeof(char *), map->nb_rows + 1);
	if (copy == NULL)
		return (1);
	copy[map->nb_rows] = 0;
	i = 0;
	while (i < map->nb_rows)
	{
		copy[i] = ft_strdup(map->mat[i]);
		i++;
	}
	flood_fill(copy, start.y, start.x);
	flag = 0;
	while (--i >= 0)
	{
		if (ft_strchr(copy[i], 'E') != NULL || ft_strchr(copy[i], 'C') != NULL)
			flag = 1;
	}
	free(copy);
	if (flag == 1)	
		return (1);
	return (0);
}

int	map_val(t_map *map)
{
	char	*map_str;
	int		nb_lines;
	t_point	start;
	int i;

	nb_lines = 0;
	map_str = f_to_str(map -> path);
	map->mat = ft_split(map_str, '\n');
	i = -1;
	while (map->mat[++i] != 0)
		nb_lines++;
	if (map_rec(map->mat) == 1) //la mappa non è rettangolare
		return (1);
	map->nb_rows = nb_lines;
	map->nb_cols = ft_strlen(map->mat[0]);
	if (map_char(map) == 1) //nella mappa non sono presenti i caratteri giusti
		return (2);
	start = find_start(map);
	if (map_fill(map, start) == 1) //mappa non percorribile
		return (3);
	return (0);
}