# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 20:40:36 by rmalkevy          #+#    #+#              #
#    Updated: 2017/03/04 12:24:04 by rmalkevy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = create_structure.c \
		ft_base_to_10.c \
		change_picture.c \
		write_picture.c \
		color.c \
		main.c

OBJ = $(SRC:.c=.o)

CC = gcc

INC = ./

LIB = -L ./libft/ -lft
LIBMLX = -L ./minilibx/ -lft

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./libft/
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(LIBMLX) -lmlx -framework OpenGL -framework AppKit

%.o: %.c
		$(CC) -c $<

clean:
		make -C ./libft/ clean
		rm -rf $(OBJ)

fclean: clean
		make -C ./libft/ fclean
		rm -f $(NAME)

re: fclean all