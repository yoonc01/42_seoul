# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:42:38 by hyoyoon           #+#    #+#              #
#    Updated: 2023/09/07 20:21:10 by hyoyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
SRCS = ./srcs/*.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs

all : $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $@ $(OBJS)

%.o: %.c
	$(CC) $(CFALGS) -I ./includes -c -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean
	make
