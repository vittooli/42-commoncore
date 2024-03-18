#include "../so_long.h"


char	*f_to_str(char *path)
{
  int  fd;
  char  buf[BUFFER_SIZE + 1];
  char  *ret;
  char  *tofree;
  int	i;
  
  i = 1;
  ret = ft_strdup("");
  buf[BUFFER_SIZE] = 0;
  fd = open(path, O_RDONLY);
  while(i > 0)
  {
    tofree = ret;
	i = read(fd, buf, BUFFER_SIZE);
	buf[i] = 0;
    ret = ft_strjoin(ret, buf);
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
	return (0);
}


int	flood_fill(char **map, int y, int x)
{
	map[y][x] = '1';
	if (map[y + 1][x] != '1')
		flood_fill(map, y + 1, x);
	if(map[y][x + 1] != '1')
		flood_fill(map, y, x + 1);
	if (map[y - 1][x] != '1')
		flood_fill(map, y - 1, x);
	if (map[y][x - 1] != '1')
		flood_fill(map, y, x - 1);
	return (0);
}

