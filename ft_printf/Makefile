SRCS	= ft_ptraddress.c ft_puthexa.c ft_putstr.c \
				ft_strlen.c ft_putchar.c ft_putnbr.c \
				ft_putunsigned.c ft_strrchr.c libftprintf.c
OBJS	= ${SRCS:.c=.o}

INCS	= printf.h
NAME	= libftprintf.a
LIBC	= ar -rcs
CC		= gcc
RM 		= rm -f
CFLAGS 	= -Wall -Wextra -Werror

all: ${NAME}

${NAME}:  ${OBJS}
	${LIBC} ${NAME} ${OBJS}


.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}


clean:
	${RM} ${OBJS}
	${RM} libft/*.o

fclean: clean
	${RM} ${NAME}
	${RM} libft/libft.a

re: fclean all
