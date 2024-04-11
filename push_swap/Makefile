NAME = push_swap

SRCS = main.c validation.c 
OBJS = $(SRCS:.c=.o)
LIBS = -lft -lftprintf

CC = cc
FLAGS = -Wall -Wextra -Werror -I/libft -I/printf
LDFLAGS = -L/libft -L/printf

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBS)



