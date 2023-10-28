SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_unsigned.c ft_puthexa_lower.c \
	ft_puthexa_upper.c ft_putaddress.c ft_printf.c

OBJS = ${SRC:.c=.o}

INC = .

LIBFT_PATH = ./libft

LIBFT = ${LIBFT_PATH}/libft.a

NAME = libftprintf.a

CC = gcc

CFLAG = -Wall -Wextra -Werror -g -03

AR = ar rcs

RM = rm -f

%.o : %.c
	${CC} ${CFLAGS} -c $< -I${INC}

${NAME}: ${OBJS} ${LIBFT}
	${AR} ${NAME} ${OBJS}

${LIBFT}:
	cd ${LIBFT_PATH} && make
	cp ${LIBFT} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS} ${NAME}

fclean: clean
	cd ${LIBFT_PATH} && make fclean

re: fclean all

.PHONY:	bonus all clean fclean re