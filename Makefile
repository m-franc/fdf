NAME = fdf
P_SRCS = srcs/
P_OBJS = objs/
P_LIBFT = libft/
P_MLX = minilibx/
P_INC_LIBFT = libft/includes/
CC = clang
FLAGS = -Wall -Wextra -Werror -fsanitize=address
SRCS = $(addprefix $(P_SRCS)), main.c	\
OBJS = $(patsubst %.c,%.o,$(addprefix $(P_OBJS), $(OBJS)))

.PHONY: all clean flcean re

$(P_LIBFT):
	make -C libft/

all: $(NAME)

$(NAME): $(OBJS) $(P_LIBFT)
	$(CC) $(FLAGS) -I $(P_INC_LIBFT) -c $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -lm -L $(P_LIBFT) -lft -L $(P_MLX) -lmlx -framework OpenGL -framework AppKit

leaks:  
	$(CC) -g -o $(NAME) $(OBJS) -lm -L $(P_LIBFT) -lft -L $(P_MLX) -lmlx -framework OpenGL -framework AppKit

clean:
	make clean -C $(P_LIBFT)
	rm -f $(OBJS)

flcean: clean
	make fclean -C $(P_LIBFT)
	rm -f $(NAME)

re:
	fclean all
