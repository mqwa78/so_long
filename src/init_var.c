
#include "../includes/so_long.h"

void	ft_init_var(t_map *map)
{
	map->fd = 0;
	map->width = 0;
	map->height = 0;
	map->buf = NULL;
	map->line = NULL;
	map->map = NULL;
}