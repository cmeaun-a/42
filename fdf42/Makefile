# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 22:39:09 by cmeaun-a          #+#    #+#              #
#    Updated: 2017/02/14 17:45:40 by cmeaun-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c ft_draw.c ft_map.c ft_line.c ft_strsplit_nbr.c

OBJ = $(SRC:.c=.o)

HDR = includes/

LIBFT = libft/

LIBA = libft/libft.a

FLAGS = -Wall -Werror -Wextra

FW = -framework OpenGL -framework AppKit

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cc -o $(NAME) $(LIBA) $(SRC) -lmlx $(FW)

%.o: %.c
	gcc $(FLAGS) -I$(HDR) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

