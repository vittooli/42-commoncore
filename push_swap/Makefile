# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: volivier <volivier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 16:45:38 by volivier          #+#    #+#              #
#    Updated: 2024/05/09 17:17:44 by volivier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = main.c move.c push.c rev_rotate.c rotate.c swap.c sort.c utils1.c utils2.c \
utils3.c validation.c target.c 
BONUS_SRCS = checker.c utils1.c utils2.c utils3.c validation.c push.c rotate.c rev_rotate.c \
swap.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

RM = rm -rf

.c.o:
	$(CC) $(FLAGS) -g -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	make all bonus -C libft
	make -C printf
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(PRINTF) -g -o push_swap
	
$(BONUS) : $(BONUS_OBJS)
	make all bonus -C libft
	make -C printf
	$(CC) $(BONUS_OBJS) $(CFLAGS) $(LIBFT) $(PRINTF) -g -o checker

all: $(NAME) $(BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(OBJS)
	$(RM) $(BONUS) $(BONUS_OBJS) 

re: fclean all

.PHONY: all clean fclean re .c.o




