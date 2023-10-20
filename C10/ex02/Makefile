# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 12:38:47 by hyoyoon           #+#    #+#              #
#    Updated: 2023/09/12 15:14:37 by hyoyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
TARGET = ft_tail
SRCS = ./srcs/main.c ./srcs/lib.c ./srcs/set.c
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(TARGET)

%.o :  %.c ./includes/ft.h
	$(CC) $(CFLAGS) -I ./includes -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean
	make
