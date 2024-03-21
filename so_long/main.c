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

void	set_img(t_game *g)
{
	int fuff;

	fuff = 0;
	g->img.wall = mlx_xpm_file_to_image(g->mlx, "so_long/xpm/wall.xpm", &fuff, &fuff);
	g->img.green = mlx_xpm_file_to_image(g->mlx, "so_long/xpm/green.xpm", &fuff, &fuff);
	g->img.t[0] = mlx_xpm_file_to_image(g->mlx, "so_long/xpm/t.xpm", &fuff, &fuff);
	g->img.t[1] = mlx_xpm_file_to_image(g->mlx, "so_long/xpm/dx.xpm", &fuff, &fuff);
	g->img.t[2] = mlx_xpm_file_to_image(g->mlx, "so_long/xpm/sx.xpm", &fuff, &fuff);
	g->img.t[3] = mlx_xpm_file_to_image(g->mlx, "so_long/xpm/bbl.xpm", &fuff, &fuff);//manca immagine
	g->img.soil = mlx_xpm_file_to_image(g->mlx, "so_long/xpm/soil.xpm", &fuff, &fuff);
	g->img.bud = mlx_xpm_file_to_image(g->mlx, "so_long/xpm/bud.xpm", &fuff, &fuff);
	g->img.tree = mlx_xpm_file_to_image(g->mlx, "so_long/xpm/tree.xpm", &fuff, &fuff); //manca ancora immagine
}


void	*get_image(t_game g, char c)
{
	if (c == '1')
		return (g.img.wall);
	if (c == '0')
		return (g.img.green);
	if (c == 'C')
		return (g.img.soil);
	if (c == 'G')
		return (g.img.bud);
	if (c == 'P')
		return (g.img.t[0]);
	if (c == 'E')
		return (g.img.tree);
	else
		return (NULL);
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
			x++;
		}
		y++;
	}
}

int main(int argc, char **argv)
{
	t_game	g;
	

	if (argc != 2)
		return (1);
	set_game(&g, argv[1]);
	if (map_val(&(g.map)) == 1)
		return (1);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, 1920, 1800, "So Long");
	set_img(&g);
	print_map(g);
	mlx_loop(g.mlx);
	return (0);
}