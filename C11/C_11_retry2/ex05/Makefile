# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 13:25:25 by hyoyoon           #+#    #+#              #
#    Updated: 2023/09/11 15:24:06 by hyoyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFlAGS = -Wall -Wextra -Werror
TARGET = do-op
SRCS = ./srcs/cal.c ./srcs/ft_atoi.c ./srcs/ft_putnbr.c ./srcs/ft_strcmp.c ./srcs/main.c
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(TARGET)
	
%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean
	make	
