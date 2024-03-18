#ifndef SO_LONG
# define SO_LONG

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "mlx/mlx.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef RES
# define RES 64
#endif

typedef	struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
};

typedef struct s_map
{
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;


int		map_val(t_map *map);
int		map_fill(t_map *map, t_point start);
t_point	find_start(t_map *map);
int		map_char(t_map *map);
int		map_rec(char **matrix);
int		flood_fill(char **map, int y, int x);
int		map_flags(t_map *map, int x, int y);
char	*f_to_str(char *path);

#endif