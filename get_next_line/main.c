
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"



int main()
{
	char *ret;
	int fd = open("prove", O_RDONLY);
	
	while ((ret = get_next_line1(fd)) != NULL)
	{
		// printf("%s\n", ret);
		free(ret);
	}
	close(fd);
	return (0);
}

