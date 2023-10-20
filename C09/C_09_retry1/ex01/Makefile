# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:42:38 by hyoyoon           #+#    #+#              #
#    Updated: 2023/09/09 13:02:01 by hyoyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs

all : $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $@ $(OBJS)

%.o: %.c
	$(CC) $(CFALGS) -I ./includes -c -o $@ $<

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(TARGET)

re: fclean
	make
