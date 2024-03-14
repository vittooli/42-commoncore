#include "maps.h"

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

int	map_char(t_map *map, int nb_rows)
{
	int	y;
	int x;

	y = 0;
	x = 0;
	while (y < nb_rows)
	{
		x = 0;
		while (x < ft_strlen(map->mat[0]))
		{
			if ((y == 0 || y == (nb_rows - 1) || x == 0 || x == (ft_strlen(map->mat[0]) - 1)) && map->mat[y][x] != 1)
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

t_point	find_start(t_map *map, int nb_rows)
{
	t_point p;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map->mat[y][x] != 'P' && x < (ft_strlen(map->mat[0])))
	{
		y = 0;
		while (y < nb_rows)
			y++;
		x++;
	}
	p.x = x;
	p.y = y;
	return (p);
}

int	map_fill(t_map *map, t_point start, int nb_rows)
{
	int 	nb_cols;
	int		x;
	int		y;
	int 	i;
	char	**map_copy;

	nb_cols = ft_strlen(map->mat[0]);
	map_copy = ft_calloc(sizeof(* char), nb_rows);
	i = 0;
	while (i < nb_rows)
	{
		map_copy[i] = ft_strdup(map->mat[i]);
		i++;
	}
	flood_fill(map_copy, start.y, start.x); 
	free(map_copy);

}

int	map_val(t_map *map)
{
	int		fd;
	char	*map_str;
	int		nb_rows;
	t_point	start;

	nb_rows = 0;
	map_str = f_to_str(map -> path);
	map->mat = ft_split(map_str, '\n');
	while (*map->mat++)
		nb_rows++;
	if (map_rec(map->mat) == 1)
		return (1);
	if (map_char(map, nb_rows) == 1)
		return (1);
	start = find_start(map, nb_rows);
	if (map_fill(map, start, nb_rows) == 1)
		return (1);
	return (0);
}