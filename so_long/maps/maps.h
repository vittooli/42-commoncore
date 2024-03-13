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

int	map_val(t_map *map);