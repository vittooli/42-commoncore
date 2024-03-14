#ifndef STRUCTURES_H
# define STRUCTURES_H

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

#endif