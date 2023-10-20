# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 17:32:44 by hyoyoon           #+#    #+#              #
#    Updated: 2023/09/11 17:37:06 by hyoyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = ft_cat
SRCS = ./srcs/main.c
OBJS = $(SRCS:.c=.o)

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $< -o $@

$(OBJS):$(SRCS)
	$(CC) $(CFALGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(TARGET)


