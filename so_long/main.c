#include "maps.h"
int main()
{
	t_map	*map;

	map = NULL;
	map->path = "/Users/vittoriaoliviero/Desktop/github/so_long/maps/map_test1.ber";
	printf("%d",map_val(map));
}