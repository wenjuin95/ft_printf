SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_unsigned.c ft_puthexa_lower.c \
	ft_puthexa_upper.c ft_putaddress.c ft_printf.c

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
	${RM} ${OBJS} ${NAME}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	bonus all clean fclean re
