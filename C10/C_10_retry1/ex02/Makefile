# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 14:56:44 by hyoyoon           #+#    #+#              #
#    Updated: 2023/09/14 15:17:43 by hyoyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = ft_tail
HEAD = ./includes/my.h
SRCS = ./srcs/main.c ./srcs/process.c ./srcs/string.c ./srcs/util.c
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$.o:$.c $(HEAD)
	$(CC) $(CFALGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(TARGET)

re: fclean
	make
