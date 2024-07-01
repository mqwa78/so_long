SRC	=	./src/main.c
SRC	+=	./src/check_arg.c
SRC	+=	./src/error_free.c
SRC	+=	./src/init_var.c
SRC	+=	./src/create_map.c
SRC	+=	./src/check_map.c
SRC	+=	./src/floodfill.c
SRC	+=	./src/get_next_line.c
SRC	+=	./src/get_next_line_utils.c
SRC	+=	./src/so_long.c

OBJ	=	$(SRC:.c=.o)
LIBFT = ./libft
MINILIBX = ./minilibx
LIBX = -L ./minilibx -lmlx -Ilmlx -lXext -lX11 -lm -lbsd
INLIBFT = -L./libft -lft
NAME	=	so_long
CC	=	cc
CFLAGS	= -Wall -Wextra -Werror -g
CFLAGS += -I includes/

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
		@make -C $(LIBFT)
		@make -C $(MINILIBX)
		$(CC) $(OBJ) $(INLIBFT) $(LIBX) $(CFLAGS) -o $(NAME)

clean :
	@make clean -C $(LIBFT)
	@make clean -C $(MINILIBX)
	rm -rf $(OBJ)

fclean : clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(MINILIBX)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re