#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 700
#define HEIGHT 500
#define MALLOC_ERROR 1

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;	

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int	close(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	
	return (0);
}


int	main()
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL) //controllo dell'allocazione
		return (MALLOC_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "First window");
	if (data.win_ptr == NULL) //controllo dell'allocazione
		return (MALLOC_ERROR);
	mlx_hook(data.win_ptr, 17, 1L<<0, close, &data);
	mlx_loop(data.mlx_ptr);

}
