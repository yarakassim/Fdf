


NAME = fdf

SRCS =     main.c

OBJS         =     ${SRCS:.c=.o}

PATH_MLX    =    ./mlx
GNL			=	./getnextline/get_next_line.c
PATH_LIBFT		= ./libft
CC             =     gcc
CFLAGS        =     -Wall -Wextra -Werror -g
LIB         =   mlx/libmlx.a
RM            =     rm -f
NAME        =     fdf
FLAGS        =     -ldl -Imlx -Lmlx -lmlx -lm -lXext -lX11 

all:             ${NAME}

.c.o:
	${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C $(PATH_MLX)
	make -C $(PATH_LIBFT)
	${CC} $(CFLAGS) $(GNL)
	${CC} $(CFLAGS) $(OBJS) $(FLAGS) $(LIB) -o $(NAME)

clean:
	make -C $(PATH_MLX) clean
	make -C $(PATH_LIBFT) clean
	${RM} ${OBJS} 

fclean:         clean
	${RM} ${NAME} 

re:             fclean all

.SILENT:        $(NAME)

.PHONY:            bonus all clean fclean re
    #OBJS = $(SRCS:.c=.o)







