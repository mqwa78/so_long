
#include "../includes/so_long.h"

int	ft_up_down(t_map *map)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (map->map[0][i] && map->map[0][i] != '\n')
	{
		if (map->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	len = map->height - 1;
	while (map->map[len][i] && map->map[len][i] != '\n')
	{
		if (map->map[len][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_left_right(t_map *map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = map->width - 1;
	while (i < map->height)
	{
		if (map->map[i][0] != '1')
			return (0);
		if (map->map[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_map(t_map *map)
{	
	size_t	i;

	if (map->width < 3 || map->height < 3 || map->width == map->height)
		return (0);
	if (map->con < 1 || map->start != 1 || map->end != 1)
		return (0);
	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) != map->width)
			return (0);
		i++;
	}
	if (!ft_up_down(map) || !ft_left_right(map))
		return (0);
	if (!ft_floodfill(map))
		return (0);
	return (1);
}