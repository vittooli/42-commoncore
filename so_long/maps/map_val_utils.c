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

void	flood_fill(char **map, int y, int x)
{
	map[y][x] = '-';
	if (map[y + 1][x] != '1')
		flood_fill(map, y + 1, x);
	if (map[y][x + 1] != '1')
		flood_fill(map, y, x + 1);
	if (map[y - 1][x] != '1')
		flood_fill(map, y - 1, x);
	if (map[y][x - 1] != '1')
		flood_fill(map, y, x - 1);
}

