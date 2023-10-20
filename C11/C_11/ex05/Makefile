# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 13:25:25 by hyoyoon           #+#    #+#              #
#    Updated: 2023/09/10 15:37:12 by hyoyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFlAGS = -Wall -Wextra -Werror
TARGET = do-op
HEAD = ./ft.h
SRCS = ./cal.c ./ft_atoi.c ./ft_putnbr.c ./ft_strcmp.c ./main.c
MAIN = main.c
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(TARGET)
	
%.o: %.c $(HEAD) 
	$(CC) $(CFLAGS) -I ./ -c -o $@ $<

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
