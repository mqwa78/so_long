

/*

ft_check incremente var etat si conso et end = 0
copy map + vars conso et end
creer var bool etat

*/


int	flood(t_map *map, int x, int y)
{
	if (cpy[x][y] == 'C' || cpy[x][y] == 'E')
	{
		if (cpy[x][y] == 'C')
			conso--;
		else
			end--;
		if (ft_check(t_map *map) == 1)
		return (1);
	}
	cpy[x][y] == '1';
	if (!etat && cpy[x + 1][y] != '1')
		flood(t_map *map, [x + 1][y]);
	if (!etat && cpy[x - 1][y] != '1')
		flood(t_map *map, [x - 1][y]);
	if (!etat && cpy[x][y + 1] != '1')
		flood(t_map *map, [x][y + 1]);
	if (!etat && cpy[x][y - 1] != '1')
		flood(t_map *map, [x][y - 1]);
	if (etat)
		return (1);
	return (0);
}