PROG    = so_long

SRCS    =	main.c maps/map_val.c maps/map_val_utils

OBJS     = ${SRCS:.c=.o}
MAIN    = main.c

HEADER    = -Iinclude

CC         = gcc
CFLAGS     = -Wall -Wextra -Werror -g

.c.o:        %.o : %.c
	@gcc ${CFLAGS} ${HEADER} -Imlx -c $< -o $(<:.c=.o)

all:         ${PROG}

${PROG}:    ${OBJS}
						@echo "\033[33m----Compiling lib----"
						@$(CC) ${OBJS} -lmlx -lXext -lX11 -L mlx -o ${PROG} ft_printf/libftprintf.a maps/libft/libft.a
						@echo "\033[32mSo Long Compiled!\n"

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

#mlx 
#make 
#./configure 

#printf make  make clean -o ti lasci libftprintf.a