# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 12:08:29 by hyoyoon           #+#    #+#              #
#    Updated: 2024/04/30 14:49:00 by hyoyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
FLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = fractol
SRCS = burningship.c hook.c init.c julia.c main.c mandelbrot.c tool.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean
	make

.PHONY: all clean fclean re
