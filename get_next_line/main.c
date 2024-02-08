
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"



/*int main()
{
	char *ret;
	int fd = open("prove", O_RDONLY);
	int i = 0;
	
	while (i < 5)
	{
		//printf("%s", ret);
		ret = get_next_line(fd);
		i++;
		free(ret);
	}
	close(fd);
	return (0);
}*/

int main()
{
	char *ret;
	int fd = open("prove", O_RDONLY);

	while ((ret = get_next_line(fd)) != NULL)
	{
		printf("%s", ret);
		free(ret);
	}
	close(fd);
	return (0);
}