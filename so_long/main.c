#include "so_long.h"

void	set_game(t_game *game, char *path)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.path = path;
	game->map.C = 0;
	game->map.E = 0;
	game->map.P = 0;
	game->map.mat = NULL;
	game->map.nb_rows = 0;
	game->map.nb_cols = 0;
}


void	*get_image(t_game g, char c)
{
	if (c == '1')
		return (g.map.)
}

void	print_map(t_game g)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < g.map.nb_rows)
	{
		x = 0;
		while (x < g.map.nb_cols)
		{
			img = get_image(g, g.map.mat[y][x]);
			mlx_put_image_to_window(g.mlx, g.win, img, x * RES, y * RES);
		}
	}
}

int main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		return (1);
	set_game(&g, argv[1]);
	if (map_val(&map) == 1)
		return (1);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 1920, 1800, "So Long");
	print_map(g);
	mlx_loop(map.mlx);
}