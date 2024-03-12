#include <fcntl.h>
#include <stdio.h>

typedef struct s_map
{
	void	*mlx;
	void	*win;
	char	*path;
}	t_map;

char	*f_to_str(char *path)
{
	int		fd;
	char	*ret;
	
	fd = open(path, O_RDONLY);
	ret = 

}

int	matrix(t_map *map) //glielo passo come pointer (perché?)
{
	int		fd;
	char	*matrix;

	matrix = f_to_str(map -> path);
}