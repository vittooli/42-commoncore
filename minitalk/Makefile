# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: volivier <volivier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 12:41:00 by volivier          #+#    #+#              #
#    Updated: 2024/06/22 00:20:44 by volivier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
PRINTF = ./printf/libftprintf.a

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(PRINTF) -g -o client

$(SERVER): $(SERVER_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(PRINTF) -g -o server

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(PRINTF) -g -o client_bonus
	
$(SERVER_BONUS): $(SERVER_BONUS_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(PRINTF) -g -o server_bonus
.c.o:
	$(CC) $(FLAGS) -g -c $< -o $(<:.c=.o)

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re .c.o
