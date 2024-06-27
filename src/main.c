
#include "../includes/so_long.h"

int	main(int ac, char **av)
{	
	t_map		map;
	size_t		size;

	if (ac == 2)
	{
		ft_init_var(&map);
		if (!ft_check_arg(av[1]))
			ft_error(&map, 0);
		ft_create_map((av[1]), &map);
		if (!ft_check_map(&map))
		{
			ft_free_map(&map, map.height);
			write(2, "invalid map\n", 12);
			return (1);
		}
		//so_long(&map);
	size = 0;
	while (size < map.height)
	{
		printf("%s\n", map.map[size]);
		size++;
	}
	ft_free_map(&map, map.height);
	}
	else
	{	
		write(2, "no arguments or too much\n", 25);
		return (1);
	}
	return (0);
}