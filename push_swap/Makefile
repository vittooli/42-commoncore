# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: volivier <volivier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 16:45:38 by volivier          #+#    #+#              #
#    Updated: 2024/04/28 20:21:35 by volivier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = main.c move.c push.c rev_rotate.c rotate.c swap.c sort.c utils.c validation.c target.c 
LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a

OBJS = $(SRCS:.c=.o)

RM = rm -rf

.c.o:
	$(CC) $(FLAGS) -g -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	make all bonus -C libft
	make -C printf
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(PRINTF) -g -o push_swap
	

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re .c.o




