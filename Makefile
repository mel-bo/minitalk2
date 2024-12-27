CC = gcc -std=gnu99
FLAGS = -Wall -Werror -Wextra -I libft -I ft_printf
INC = -L./libft -lft -L./ft_printf -lftprintf
NAME_CLIENT = client
NAME_SERVER = server

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}

all: ${NAME_CLIENT} ${NAME_SERVER}
	
${NAME_CLIENT}: ${OBJS_CLIENT}
	@make -C ft_printf
	@make -C libft
	${CC} ${FLAGS} ${OBJS_CLIENT} -o ${NAME_CLIENT} ${INC}

${NAME_SERVER}: ${OBJS_SERVER}
	${CC} ${FLAGS} ${OBJS_SERVER} -o ${NAME_SERVER} ${INC}

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@${RM} ${OBJS_CLIENT} ${OBJS_SERVER}

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@${RM} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all
.PHONY: all clean fclean re