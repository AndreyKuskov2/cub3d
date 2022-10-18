#ifndef CUB3D_H
#define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/io.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_map t_map;

struct s_test
{};

struct s_map
{
	char **map;
	char *side_of_world[4];
	char *ceiling_floor[2];
	void *mlx;
	void *north;
	void *south;
	void *west;
	void *east;
};

#endif