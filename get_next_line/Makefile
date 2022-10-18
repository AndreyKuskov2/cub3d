NAME = gnl.a

HEADER = get_next_line.h

SRC = ${wildcard ./*.c}

OBJ = ${SRC:.c=.o}

GCC		= gcc -Wall -Wextra -Werror

AR 		= ar -rcs

RM 		= rm -f

.c.o:
		${GCC} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ} ${HEADER}
		${AR} ${NAME} ${OBJ}

clean:
		${RM} ${OBJ}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all bonus

.PHONY: bonus all clean fclean re