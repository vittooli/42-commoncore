#include "maps.h"

char  *f_to_str(char *path)
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

void	flood_fill(t_map *map, int y, int x)
{
	map->mat[y][x] = '1';
	if (map->mat[y + 1][x] != '1')
		flood_fill(map, y + 1, x);
	if(map->mat[y][x + 1] != '1')
		flood_fill(map, y, x + 1);
	if (map->mat[y - 1][x] != '1')
		flood_fill(map, y - 1, x);
	if (map->mat[y][x - 1] != '1')
		flood_fill(map, y, x - 1);
}

int	map_fill(t_map *map, t_point start)
{
	t_map	*copy;
	int 	i;
	int 	flag;
	int		j = 0;

	copy->mat = ft_calloc(sizeof(char *), map->nb_rows + 1);
	if (copy->mat == NULL)
		return (1);
	copy->mat[map->nb_rows] = 0;
	i = 0;
	while (i < map->nb_rows)
	{
		copy->mat[i] = ft_strdup(map->mat[i]);
		i++;
	}
	flood_fill(copy, start.y, start.x);
	while (j < map->nb_rows)
	{
		printf("%s\n", copy->mat[j]);
		j++;
	}
	flag = 0;
	while (--i >= 0)
	{
		if (ft_strchr(copy->mat[i], 'E') != NULL && ft_strchr(copy->mat[i], 'C') != NULL)
			flag = 1;
	}
	printf("hellooo\n");
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
	int i;

	nb_lines = 0;
	map_str = f_to_str(map -> path);
	map->mat = ft_split(map_str, '\n');
	i = -1;
	/* while(map->mat[i] != 0)
	{
		printf("%s\n", map->mat[i]);
		i++;
	}  */
	while (map->mat[++i] != 0)
		nb_lines++;
	printf("nb_lines: %d\n", nb_lines);
	if (map_rec(map->mat) == 1)
		return (1);
	map->nb_rows = nb_lines;
	map->nb_cols = ft_strlen(map->mat[0]);
	if (map_char(map) == 1)
		return (2);
	start = find_start(map);
	printf("qu\n");
	if (map_fill(map, start) == 1)
		return (3);
	return (0);
}