PROG    = so_long

SRCS    =	main.c maps/map_val.c maps/map_val_utils.c

OBJS     = ${SRCS:.c=.o}
MAIN    = main.c

HEADER    = -Iinclude

CC         = gcc
CFLAGS     = -Wall -Wextra -Werror -g

.c.o:        %.o : %.c
	@gcc ${CFLAGS} libft/libft.a ${HEADER} -Imlx -c $< -o $(<:.c=.o)  

all:         ${PROG}

${PROG}:    ${OBJS}
						@$(CC) ${OBJS}  -Lmlx -lmlx -lXext -lX11 -o ${PROG} ft_printf/libftprintf.a libft/libft.a

clean:
						@rm -f ${OBJS}


fclean:     clean
						@rm -f $(NAME)
						@rm -f ${PROG}
						@echo "\n\033[31mDeleting EVERYTHING!\n"

git:
	git add .
	git commit -m "update"
	git push

re:            fclean all

.PHONY: all clean fclean re