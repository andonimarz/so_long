# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:17:29 by amarzana          #+#    #+#              #
#    Updated: 2022/08/17 11:40:02 by amarzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
CFLAGS_MINILIBX = -L . -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)
SRC_DIR = src
LIB_FT = libft
LIB_MINILIBX = minilibx

GREEN 	= "\\x1b[32m"
RED 	= "\\x1b[31m"
RESET 	= "\\x1b[37m"

SRC = 	$(SRC_DIR)/so_long.c						\
		$(SRC_DIR)/ft_checks.c						\
		$(SRC_DIR)/ft_checks2.c						\
		$(SRC_DIR)/ft_utils.c						\
		$(SRC_DIR)/ft_mlx.c							\
		$(SRC_DIR)/ft_inputs.c

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	echo $(GREEN)Compiling libft$(RESET)
	make bonus -C $(LIB_FT)
	echo "$(GREEN)Compiling minilibx$(RESET)"
	make -C $(LIB_MINILIBX) 2>mlx_warnings.log
	mv ./minilibx/libmlx.a .
	echo $(GREEN)Compiling so_long$(RESET)
	${CC} ${CFLAGS} ${CFLAGS_MINILIBX} $(OBJ) $(LIB_FT)/libft.a libmlx.a -o $(NAME)
	echo $(GREEN)Mandatory: Compilation done!$(RESET)

clean:
	rm -f $(OBJ)
	rm mlx_warnings.log
	$(MAKE) -C ./minilibx/ clean
	echo $(RED)Object files removed$(RESET)

fclean: clean
	make fclean -C $(LIB_FT)
	rm libmlx.a
	rm -f $(NAME)
	echo $(RED)Executable file removed$(RESET)

re: fclean all

.PHONY: all clean fclean re leaks