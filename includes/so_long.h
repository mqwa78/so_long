
#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef int	t_bool;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct map_s
{
	int			fd;
	int			start;
	int			con;
	int			end;
	int			cpyend;
	int			cpycon;
	int			etat;
	int			player_x;
	int			player_y;
	int			counter;
	size_t		width;
	size_t		height;
	char		*line;
	char		*buf;
	char		**map;
	char		**cpy;
}						t_map;

typedef struct game_s
{
	void		*mlxptr;
	void		*winptr;
	void		*wall;
	void		*floor;
	void		*conso;
	void		*exit;
	void		*player;
}						t_game;

/*          MAP              */

int		ft_check_arg(char *str);
int		ft_check_suf(char *str, int pos);
void	ft_error(t_map *map, int flag);
void	ft_free_var(t_map *map);
void	ft_init_var(t_map *map);
void	ft_create_map(char *file, t_map *map);
void	ft_free_map(t_map *map, int size);
void	ft_free_cpy(t_map *map, int size);
int		ft_check_line(char *line, t_map *map);
int		ft_check_char(char c, char *str);
int		ft_check_map(t_map *map);
int		ft_up_down(t_map *map);
int		ft_left_right(t_map *map);
int		ft_floodfill(t_map *map);
char	**ft_map_cpy(t_map map);
int		ft_flood(t_map *map, int x, int y);
int		ft_check_var(t_map *map);

/*          GNL             */

size_t	gnlen(const char *str);
size_t	ft_count_char(const char *str);
t_bool	ft_check_endline(const char *str);
char	*get_next_line(int fd, t_map *map);
char	*gnl_strjoin(char *storage, char *buffer);
char	*ft_create_line(char *str, t_map *map);
char	*ft_fill_storage(char *storage, int fd);
char	*ft_new_storage(char *storage);
#endif