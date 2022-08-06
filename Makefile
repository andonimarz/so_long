# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:17:29 by amarzana          #+#    #+#              #
#    Updated: 2022/08/06 12:11:04 by amarzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
OBJ = $(SRC:.c=.o)
LIB_FT = libft
LIB_GNL = gnl
LIB_MINILIBX = minilibx

GREEN 	= "\\x1b[32m"
RED 	= "\\x1b[31m"
RESET 	= "\\x1b[37m"

SRC = 	so_long.c						\
		$(LIB_GNL)/get_next_line.c		\
		$(LIB_GNL)/get_next_line_utils.c


all: $(NAME)

$(NAME): $(OBJ)
	@echo $(GREEN)Compiling libft$(RESET)
	@make bonus -C $(LIB_FT)
	@echo $(GREEN)Compiling so_long$(RESET)
	@${CC} ${CFLAGS} $(OBJ) $(LIB_FT)/libft.a -o $(NAME)
	@echo $(GREEN)Mandatory: Compilation done!$(RESET)

clean:
	@rm -f $(OBJ)
	@echo $(RED)Object files removed$(RESET)

fclean: clean
	@make fclean -C $(LIB_FT)
	@make clean -C $(LIB_MINILIBX)
	@rm -f $(NAME)
	@echo $(RED)Executable file removed$(RESET)

re: fclean all

.PHONY: all clean fclean re bonus