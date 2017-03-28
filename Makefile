# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:24:51 by mfranc            #+#    #+#              #
#    Updated: 2017/03/28 13:07:42 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
P_SRCS = srcs/
P_OBJS = objs/
P_LIBFT = libft/
P_MLX = minilibx/
P_INC_LIBFT = libft/includes/
P_INC_FDF = includes/
ALL_INC = -I $(P_INC_FDF) -I $(P_INC_LIBFT) -I $(P_MLX)
CC = clang
FLAGS = -Wall -Wextra -Werror -fsanitize=address
G_FLAGS = -framework OpenGL -framework AppKit
ALL_LIB = -lm -L $(P_LIBFT) -lftprintf -L $(P_MLX) -lmlx
SRCS = $(addprefix $(P_SRCS), main.c)
OBJS = $(SRC:%.c=../$(P_OBJS)%.o)

.PHONY: all clean flcean re

all: $(NAME)

lib:
	@make -C $(P_LIBFT)
	@make -C $(P_MLX)

$(NAME): lib $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(ALL_INC) $(ALL_LIB) $(G_FLAGS)

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
