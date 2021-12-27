# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 13:36:14 by ykassim-          #+#    #+#              #
#    Updated: 2021/12/27 14:52:17 by ykassim-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

SRCS =     main.c

OBJS         =     ${SRCS:.c=.o}

PATH_MLX    =    ./mlx
PATH_LIBFT		= ./libft
CC             =     gcc
CFLAGS        =     -Wall -Wextra -Werror
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







