# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 14:01:52 by cmeaun-a          #+#    #+#              #
#    Updated: 2017/03/17 05:34:57 by cmeaun-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC = main.c ft_init.c ft_key_mouse.c ft_rt.c ft_draw.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/

LIBA = libft/libft.a

FLAGS = -Wall -Werror -Wextra -Ofast

FW = -framework OpenGL -framework AppKit

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cc -o $(NAME) $(LIBA) $(SRC) -lmlx $(FW)

%.o: %.c
	gcc $(FLAGS) -I . -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

