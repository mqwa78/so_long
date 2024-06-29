
#include "../includes/so_long.h"

//size > 0 plutot que size >= 0

void	ft_free_map(t_map *map, int size)
{
	while (size >= 0)
	{
		free(map->map[size]);
		size--;
	}
	free(map->map);
}

void	ft_free_cpy(t_map *map, int size)
{	
	size--;
	while (size >= 0)
	{
		free(map->cpy[size]);
		size--;
	}
	free(map->cpy);
}

void	ft_free_var(t_map *map)
{	
	if (map->line)
		free(map->line);
	if (map->buf)
		free(map->buf);
}

void	ft_error(t_map *map, int flag)
{	
	ft_free_var(map);
	if (flag == 0)
		write(2, "Wrong file\n", 11);
	else if (flag == 1)
		write(2, "can't read file\n", 16);
	else if (flag == 2)
		write(2, "read fail\n", 10);
	else if (flag == 3)
		write(2, "malloc fail\n", 12);
	else if (flag == 4)
		write(2, "invalid char in string\n", 23);
	exit(1);
}