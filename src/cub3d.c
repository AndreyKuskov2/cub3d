#include "cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strcpy(char *str)
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int check_file_ext(char *file_path)
{
	int len;

	len = ft_strlen(file_path);
	if (file_path[len - 4] == '.' && file_path[len - 3] == 'c' 
		&& file_path[len - 2] == 'u' && file_path[len - 1] == 'b')
		return (1);
	return (0);
}

static int read_and_validate_side_of_world_and_celling_floor(int fd, t_map *map)
{
	char *str;
	char **data;
	int i;

	i = 0;
	str = get_next_line(fd);
	if (str == NULL)
		return (0);
	while (str)
	{
		if (str[0] != '\0')
		{
			data = ft_split(str, ' ');
			if (ft_strcmp(data[0], "NO") == 0)
			{
				i++;
				map->side_of_world[0] = ft_strcpy(data[1]);
				// map->north = mlx_xpm_file_to_image(map->mlx, side_path[1], 64, 64);
			}
			else if (ft_strcmp(data[0], "SO") == 0)
			{
				i++;
				map->side_of_world[1] = ft_strcpy(data[1]);
				// map->south = mlx_xpm_file_to_image(map->mlx, side_path[1], 64, 64);
			}
			else if (ft_strcmp(data[0], "WE") == 0)
			{
				i++;
				map->side_of_world[2] = ft_strcpy(data[1]);
				// map->west = mlx_xpm_file_to_image(map->mlx, side_path[1], 64, 64);
			}
			else if (ft_strcmp(data[0], "EA") == 0)
			{
				i++;
				map->side_of_world[3] = ft_strcpy(data[1]);
				// map->east = mlx_xpm_file_to_image(map->mlx, side_path[1], 64, 64);
			}
			else if (ft_strcmp(data[0], "F") == 0)
			{
				i++;
				map->ceiling_floor[0] = ft_strcpy(data[1]);
			}
			else if (ft_strcmp(data[0], "C") == 0)
			{
				i++;
				map->ceiling_floor[1] = ft_strcpy(data[1]);
			}
			else
				return (0);
		}
		free(str);
		if (i != 6)
			str = get_next_line(fd);
		else
			break ;
	}
	return (1);
}

int validate_map(t_map *map)
{
	return (1);
}

int read_and_validate_map(int fd, t_map *map, int map_lines)
{
	char *str;
	int i;

	map->map = (char **)malloc(sizeof(char *) * map_lines);
	if (!map->map)
		return (0);
	str = get_next_line(fd);
	i = 0;
	if (str == NULL)
		return (0);
	while (str)
	{
		if (str[0] != '\0')
		{
			map->map[i] = ft_strcpy(str);
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	if (!validate_map(map))
		return (0);
	return (1);
}

int ft_count_map_lines(char *file_path)
{
	int fd;
	int i;
	char *str;
	char **data;

	i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	str = get_next_line(fd);
	if (str == NULL)
		return (-1);
	while (str)
	{
		if (str[0] != '\0')
		{
			data = ft_split(str, ' ');
			if (ft_strcmp(data[0], "NO") == 0)
				i++;
			else if (ft_strcmp(data[0], "SO") == 0)
				i++;
			else if (ft_strcmp(data[0], "WE") == 0)
				i++;
			else if (ft_strcmp(data[0], "EA") == 0)
				i++;
			else if (ft_strcmp(data[0], "F") == 0)
				i++;
			else if (ft_strcmp(data[0], "C") == 0)
				i++;
			else
				return (0);
		}
		free(str);
		if (i != 6)
			str = get_next_line(fd);
		else
			break ;
	}
	i = 0;
	str = get_next_line(fd);
	if (str == NULL)
		return (-1);
	while (str)
	{
		if (str[0] != '\0')
			i++;
		free(str);
		str = get_next_line(fd);
	}
	return (i);
}

int read_and_validate_file(char *file_path, t_map *map)
{
	int fd;
	int len;

	if (!check_file_ext(file_path))
	{
		write(2, "Error:\nFile extension must be .cub\n", 35);
		return (0);
	}
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error:\nFailed to open file\n", 27);
		return (0);
	}
	len = ft_count_map_lines(file_path);
	// printf("lines = %d\n", len);
	if (len == -1)
	{
		write(2, "Error:\nFailed to open file\n", 27);
		return (0);
	}
	if (!read_and_validate_side_of_world_and_celling_floor(fd, map))
	{
		write(2, "Error:\nCheck cardinal points in file\n", 37);
		return (0);
	}
	if (!read_and_validate_map(fd, map, len))
	{
		write(2, "Error:\nCheck the map in the file\n", 34);
		return (0);
	}



	// char *str;
	// int i;

	// i = 0;
	// str = get_next_line(fd);
	// if (str == NULL)
	// 	return (0);
	// while (str)
	// {
	// 	printf("%s\n", str);
	// 	free(str);
	// 	str = get_next_line(fd);
	// 	i++;
	// }

	return (1);
}

int main(int argc, char **argv)
{
	t_map map;

	if (argc != 2)
	{
		write(2, "Error:\nThe number of input parameters must be 2\n", 48);
		return (0);
	}
	if (!read_and_validate_file(argv[1], &map))
		return (0);
	// for (int i = 0; i < 4; i++)
	// 	printf("%s\n", map.side_of_world[i]);

	// for (int i = 0; i < 2; i++)
	// 	printf("%s\n", map.ceiling_floor[i]);

	for (int i = 0; i < 14; i++)
		printf("%s\n", map.map[i]);
	// void	*mlx;
	// void	*mlx_win;

	// printf("%ld\n", ft_strlen("Hello world!"));
	// (void)argc;
	// (void)argv;
	// (void)mlx_win;
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 500, 600, "Hello world!");
	// mlx_loop(mlx);
	return (0);
}