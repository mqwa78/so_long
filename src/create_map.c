
#include "../includes/so_long.h"

int	ft_check_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_line(char *line, t_map *map)
{	
	int		i;

	i = 0;
	if (!line)
		return (1);
	while (line[i] && line[i] != '\n')
	{
		if (!ft_check_char(line[i], "01CPE"))
			return (0);
		if (line[i] == 'C')
			map->con++;
		else if (line[i] == 'P')
		{
			map->start++;
			map->player_x = i;
			map->player_y = map->height;
		}
		else if (line[i] == 'E')
			map->end++;
		i++;
	}
	return (1);
}

void	ft_create_map(char *file, t_map *map)
{	
	map->fd = open(file, O_RDONLY);
	map->line = get_next_line(map->fd, map);
	map->width = ft_strlen(map->line);
	while (map->line != NULL)
	{
		map->buf = gnl_strjoin(map->buf, map->line);
		if (map->buf == NULL)
			ft_error(map, 3);
		map->height++;
		free(map->line);
		map->line = NULL;
		map->line = get_next_line(map->fd, map);
	}
	map->map = ft_split(map->buf, '\n');
	if (map->map == NULL)
		ft_error(map, 3);
	free(map->buf);
	close(map->fd);
}