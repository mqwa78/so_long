SRC	=	./src/main.c
SRC	+=	./src/check_arg.c
SRC	+=	./src/error_free.c
SRC	+=	./src/init_var.c
SRC	+=	./src/create_map.c
SRC	+=	./src/get_next_line.c
SRC	+=	./src/get_next_line_utils.c

OBJ	=	$(SRC:.c=.o)
LIBFT = ./libft
INLIBFT = -L./libft -lft
NAME	=	so_long
CC	=	cc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS += -I includes/

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
		@make -C $(LIBFT)
		$(CC) $(OBJ) $(INLIBFT) $(CFLAGS) -o $(NAME)

clean :
	@make clean -C $(LIBFT)
	rm -rf $(OBJ)

fclean : clean
	@make fclean -C $(LIBFT)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re