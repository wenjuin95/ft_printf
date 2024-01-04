SRC = print_alpha.c print_number.c ft_putaddress.c ft_printf.c

OBJS = ${SRC:.c=.o}

NAME = libftprintf.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

%.o : %.c
	${CC} ${CFLAG} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re