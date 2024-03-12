#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct s_map
{
	void	*mlx;
	void	*win;
	char	*path;
	int		C;
	int		P;
	int		E;
	char	**mat;
}	t_map;

typedef struct s_point
{
	int	x;
	int y;
}	t_point;


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

t_point	find_start(t_map *map)
{
	t_point point;
	
}

int	map_fill(t_map *map, t_point)
{

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
	while (*map->mat++)
		nb_lines++;
	if (map_rec(map->mat) == 1)
		return (1);
	if (map_char(map, nb_lines) == 1)
		return (1);
	start = find_start(map);
	if (map_fill(map, ) == 1)
		return (1);
	return (0);
}