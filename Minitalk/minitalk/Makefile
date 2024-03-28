# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 20:13:05 by hyoyoon           #+#    #+#              #
#    Updated: 2024/03/28 18:47:26 by hyoyoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = 
CLIENT = client
SERVER = server
SRCS_S = ./server.c
SRCS_C = ./client.c
SRCS = ./ft_atoi.c ./ft_isdigit.c

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	$(CC) $(CFLAGS) -o $(SERVER) $(SRCS_S) $(SRCS)

$(CLIENT):
	$(CC) $(CFLAGS) -o $(CLIENT) $(SRCS_C) $(SRCS)

clean:
	rm -f $(CLIENT) $(SERVER)

fclean: 
	rm -f $(CLIENT) $(SERVER)

re: fclean
	make
