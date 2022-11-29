# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 12:45:44 by hiantrin          #+#    #+#              #
#    Updated: 2019/12/08 11:54:32 by hiantrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =  fdf.c help.c check_map.c bresenham.c help2.c alloc_and_free.c

OUT=$(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OUT) fdf.h
	make -C libft
	$(CC) $(CFLAGS) $(OUT) -L./libft -lft -o $(NAME) \
	-L /usr/local/lib -lmlx -framework OpenGl -framework AppKit

clean:
	@make clean -C libft
	@/bin/rm -f $(OUT)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
