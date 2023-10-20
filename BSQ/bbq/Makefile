# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 15:34:05 by hyoyoon           #+#    #+#              #
#    Updated: 2023/09/13 22:25:36 by hyoyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = bsq
HEAD = ./includes/ft.h
SRCS = ./srcs/main.c ./srcs/psg.c ./srcs/psg2.c ./srcs/solve.c ./srcs/split.c ./srcs/stdin.c ./srcs/util.c
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(TARGET)

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean
	make
