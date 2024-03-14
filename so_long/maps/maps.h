#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"

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
	int		nb_rows;
	int		nb_cols;
}	t_map;

typedef struct s_point
{
	int	x;
	int y;
}	t_point;

int		map_val(t_map *map);
int		map_fill(t_map *map, t_point start, int nb_rows);
t_point	find_start(t_map *map, int nb_rows);
int		map_char(t_map *map, int nb_rows);
int		map_rec(char **matrix);
void	flood_fill(char **map, int y, int x);
int 	map_flags(t_map *map, int x, int y);
char	*f_to_str(char *path);