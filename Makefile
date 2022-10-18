NAME = cub3D

HEADERS = ./includes

LIBFT = ./libft/libft.a

GNL = ./get_next_line/gnl.a

SRC = ${wildcard ./src/*.c}

OBJ = ${SRC:.c=.o}

GCC = gcc

GFLAGS = -I./includes

MLX = -L/usr/local/lib -lmlx -lX11 -lXext

.c.o:
	${GCC} -g ${GFLAGS} -I./libft -I./get_next_line -o $@ -c $< 

all: ${NAME}

${NAME}: ${LIBFT} ${GNL} ${HEADERS} ${OBJ}
	${GCC} -g ${GFLAGS} ${OBJ} -o ${NAME} ${MLX} ${LIBFT} ${GNL}

lib:
	cd ./libft && make

${LIBFT}: lib

gnl:
	cd ./get_next_line && make

${GNL}: gnl

clean:
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}
	cd ./libft && make clean
	cd ./get_next_line && make clean

fclean: clean
	${RM} ${NAME}
	cd ./libft && make fclean
	cd ./get_next_line && make fclean

re: fclean all

.PHONY: all clean fclean re
