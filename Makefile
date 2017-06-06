# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:24:51 by mfranc            #+#    #+#              #
#    Updated: 2017/06/06 23:38:57 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
P_SRCS = srcs/
P_OBJS = objs/

P_LIBFT = libft/
LIBFT = $(P_LIBFT)libftprintf.a

P_MLX = minilibx/
MLX = $(P_MLX)libmlx.a

P_INC_LIBFT = libft/includes/
P_INC_FDF = includes/
ALL_INC = -I $(P_INC_FDF) -I $(P_INC_LIBFT) -I $(P_MLX)
G_FLAGS = -framework OpenGL -framework AppKit 
CC = clang -Wall -Wextra -Werror
CMD_LIB = -lm -L $(P_LIBFT) -lftprintf -L $(P_MLX) -lmlx $(G_FLAGS)
SRCS = $(addprefix $(P_SRCS), main.c	\
	   	ft_exit_fdf.c					\
		display/ft_put_pxl_img.c		\
		ft_fdf_init.c					\
		parsing/ft_parse_map.c			\
		parsing/ft_fill_coord.c			\
		display/ft_debugging.c			\
		parsing/ft_prepare_coord.c		\
		parsing/ft_coord_new.c			\
		display/ft_putcoord_img.c		\
		display/calculation.c			\
		display/ft_get_value.c			\
		display/ft_putlpoint.c)
OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean flcean re

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $^ -o $@ $(ALL_INC) $(CMD_LIB)

$(LIBFT):
	@make -C $(P_LIBFT)

$(MLX):
	@make -C $(P_MLX)

%.o: %.c
	$(CC) -o $@ -c $< $(ALL_INC)

clean:
	@make clean -C $(P_LIBFT)
	@make clean -C $(P_MLX)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(P_LIBFT)
	@make clean -C $(P_MLX)
	rm -f $(NAME)

re: fclean all

git:
	git add -u; git commit -m "WIP"; git push

norm:
	norminette includes/ srcs/
