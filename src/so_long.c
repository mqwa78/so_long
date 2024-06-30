
#include "../includes/so_long.h"

void	ft_init_img(t_game *game)
{
	int	x;
	int	y;

	game->floor = mlx_xpm_file_to_image(game->mlxptr,
			"./images/floor.xpm", &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlxptr,
			"./images/wall.xpm", &x, &y);
	game->conso = mlx_xpm_file_to_image(game->mlxptr,
			"./images/conso.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlxptr,
			"./images/player.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlxptr,
			"./images/exit.xpm", &x, &y);
}

void	ft_setup_img(t_game *game, t_map *map, int x, int y)
{
	while (++y < map->height)
	{
		while (++x < map->width)
		{
			if (map->map[x][y] == '0')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->floor, x * 64, y * 64);
			else if (map->map[x][y] == '1')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->floor, x * 64, y * 64);
			else if (map->map[x][y] == 'C')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->floor, x * 64, y * 64);
			else if (map->map[x][y] == 'P')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->floor, x * 64, y * 64);
			else if (map->map[x][y] == 'E')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->floor, x * 64, y * 64);
		}
	}
}

void	so_long(t_map *map)
{
	t_game	game;

	game.mlxptr = mlx_init();
	game.winptr = mlx_new_window(game.mlxptr, (map->width * 64),
			(map->height * 64), "so_long");
	ft_init_img(&game);
	ft_setup_img(&game, map, -1, -1);
	mlx_hook(game.winptr, 02, 1L, ft_controls, &game);
	mlx_hook(game.winptr, 17, 0, ft_close_game, &game);
	mlx_loop(game.mlxptr);
}