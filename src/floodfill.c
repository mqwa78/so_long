
#include "../includes/so_long.h"

int	ft_check_var(t_map *map)
{
	if (map->cpycon == 0 && map->cpyend == 0)
	{
		map->etat = 1;
		return (1);
	}
	return (0);
}

int	ft_flood(t_map *map, int x, int y)
{
	if (map->cpy[x][y] == 'C' || map->cpy[x][y] == 'E')
	{
		if (map->cpy[x][y] == 'C')
			map->cpycon--;
		else
			map->cpyend--;
		if (ft_check_var(map))
			return (1);
	}
	map->cpy[x][y] = '1';
	if (!map->etat && map->cpy[x + 1][y] != '1')
		ft_flood(map, x + 1, y);
	if (!map->etat && map->cpy[x - 1][y] != '1')
		ft_flood(map, x - 1, y);
	if (!map->etat && map->cpy[x][y + 1] != '1')
		ft_flood(map, x, y + 1);
	if (!map->etat && map->cpy[x][y - 1] != '1')
		ft_flood(map, x, y - 1);
	if (map->etat)
		return (1);
	return (0);
}

char	**ft_map_cpy(t_map map)
{
	size_t		i;
	char		**res;

	res = malloc(sizeof(char *) * map.height);
	if (!res)
		return (NULL);
	i = 0;
	while (i < map.height)
	{
		res[i] = ft_strdup(map.map[i]);
		if (!res[i])
		{	
			ft_free_cpy(&map, i);
			return (NULL);
		}
		i++;
	}
	return (res);
}

int	ft_floodfill(t_map *map)
{	
	int	res;

	map->cpy = NULL;
	map->cpy = ft_map_cpy(*map);
	if (!map->cpy)
		return (0);
	map->cpycon = map->con;
	map->cpyend = map->end;
	res = ft_flood(map, map->player_x, map->player_y);
	ft_free_cpy(map, map->height);
	return (res);
}
