
#include "../includes/so_long.h"

void	free_img(t_map *game)
{	
	if (game->img.exit)
		mlx_destroy_image(game->mlxptr, game->img.exit);
	if (game->img.conso)
		mlx_destroy_image(game->mlxptr, game->img.conso);
	if (game->img.player)
		mlx_destroy_image(game->mlxptr, game->img.player);
	if (game->img.floor)
		mlx_destroy_image(game->mlxptr, game->img.floor);
	if (game->img.wall)
		mlx_destroy_image(game->mlxptr, game->img.wall);
}

int	ft_close_game(t_map *game)
{
	mlx_destroy_window(game->mlxptr, game->winptr);
	free_img(game);
	ft_free_map(game, game->height);
	mlx_destroy_display(game->mlxptr);
	free(game->mlxptr);
	exit (0);
}

void	ft_init_img(t_map *game)
{
	int	x;
	int	y;

	game->img.floor = mlx_xpm_file_to_image(game->mlxptr,
			"./images/floor.xpm", &x, &y);
	game->img.wall = mlx_xpm_file_to_image(game->mlxptr,
			"./images/wall.xpm", &x, &y);
	game->img.conso = mlx_xpm_file_to_image(game->mlxptr,
			"./images/conso.xpm", &x, &y);
	game->img.player = mlx_xpm_file_to_image(game->mlxptr,
			"./images/player.xpm", &x, &y);
	game->img.exit = mlx_xpm_file_to_image(game->mlxptr,
			"./images/exit.xpm", &x, &y);
}

void	ft_setup_img(t_map *game, int x, int y)
{
	while (++y < game->height)
	{
		while (++x < game->width)
		{
			if (game->map[x][y] == '0')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->img.floor, x * 64, y * 64);
			else if (game->map[x][y] == '1')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->img.wall, x * 64, y * 64);
			else if (game->map[x][y] == 'C')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->img.conso, x * 64, y * 64);
			else if (game->map[x][y] == 'P')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->img.player, x * 64, y * 64);
			else if (game->map[x][y] == 'E')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->img.exit, x * 64, y * 64);
		}
	}
}

void	so_long(t_map *game)
{
	game->mlxptr = mlx_init();
	game->winptr = mlx_new_window(game->mlxptr, (game->width * 64),
			(game->height * 64), "so_long");
	ft_init_img(game);
	ft_setup_img(game, -1, -1);
	mlx_hook(game->winptr, 02, 1L, ft_controls, game);
	mlx_hook(game->winptr, 17, 0, ft_close_game, game);
	mlx_loop(game->mlxptr);
}