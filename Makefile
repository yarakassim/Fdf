# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykassim- <ykassim-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 13:36:14 by ykassim-          #+#    #+#              #
#    Updated: 2022/01/17 10:16:30 by ykassim-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#name of the program
NAME = fdf

#source files and object files
FILES 	=	main.c \
			draw.c \
			init.c \
			map.c \
			error.c \
			free.c \
			utils.c
SRCS	=	$(addprefix srcs/, $(FILES)) get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS	=	$(SRCS:.c=.o)

#paths
PATH_SRCS	=	./srcs/
PATH_OBJS	=	./objs/
PATH_MLX    =    ./mlx/
PATH_LIBFT		= ./libft/
PATH_INC			= ./includes/

#compilation
CC             =     gcc
CFLAGS        =     -Wall -Wextra -Werror -g


RM            =     rm -f
FLAGS        =     -ldl -Imlx -Lmlx -lmlx -lm -lXext -lX11

all:	$(NAME)

$(PATH_OBJS)%.o:$(PATH_SRCS)%.c
	${CC} ${CFLAGS} -Imlx -Ibass -I $(PATH_INC) -o $@ -c $<

$(NAME): $(OBJS)
	make -C $(PATH_MLX) 
	make -C $(PATH_LIBFT)
	${CC} $(CFLAGS) $(OBJS) -o $(NAME) $(FLAGS) libft/libft.a

clean:
	${RM} ${OBJS}
	make -C $(PATH_MLX) clean
	make -C $(PATH_LIBFT) clean

fclean:	clean
	${RM} ${NAME}
	make -C $(PATH_LIBFT) fclean

re:	fclean all
