#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 18:22:48 by pxia              #+#    #+#              #
#    Updated: 2014/12/01 13:12:40 by pxia             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
GC = gcc -Wall -Wextra -Werror
SRC = main.c mlx.c tools.c trace1.c trace2.c hook.c getinfo.c matrice.c \
	  get_next_line.c get_list.c pixelput.c

OBJ = $(SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(GC) -o $@ $^ libft/libft.a -L /usr/X11/lib -lmlx -lXext -lX11

%.o: %.c
	$(GC) -o $@ -c $<

clean:
	rm -rf *.o
	rm -rf libft/*.o

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re: fclean all