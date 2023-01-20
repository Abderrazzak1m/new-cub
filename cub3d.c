#include "cub3d.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc > 2 || argc < 2)
	{
		perror("Error: ");
	}
	else
	{
		fd = open(argv[1], O_RDONLY, 777);
		if (fd == -1)
		{
			perror("Error: ");
			return (0);
		}
        map(fd);
	}
}