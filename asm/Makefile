# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 11:02:03 by mdeglain          #+#    #+#              #
#    Updated: 2017/08/01 16:57:38 by dbischof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
CC = gcc
CFLAGS = -Wall -Wextra -Wextra
SRC_NAME =	$(sort op.c main.c parsing.c utils.c args.c finding_parse.c \
			parsing2.c verif_args.c parsing3.c translate.c write_everything.c \
			write_dir.c function.c reg.c)

LIB_PATH = ../libft/
LIB_NAME = libft.a
SRC_PATH = ./sources/
OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_PATH = ./includes/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))
INC = $(addprefix -I, $(INC_PATH))

NO_C = \e[0m\n
BLACK = \e[0;30m
GRAY = \e[0;30m
RED = \e[0;31m
LRED = \e[1;31m
GREEN = \e[0;32m
LGREEN = \e[1;32m
BROWN = \e[0;33m
YELLOW = \e[1;33m
BLUE = \e[0;34m
LBLUE = \e[1;34m
PURPLE = \e[0;35m
LPURPLE = \e[1;35m
CYAN = \e[0;36m
LCYAN = \e[1;36m
LGRAY = \e[0;37m
WHITE = \e[1;37m

.PHONY: all libft clean fclean re norme

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(LIB) $(OBJ) -o $@
	@printf "$(RED)[:D $(NAME) READY :D]$(NO_C)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@printf "$(PURPLE)[-_-|cleaned|-_-]$(NO_C)"

fclean: clean
	@rm -f $(NAME)
	@printf "$(LBLUE)[...|fcleaned|...]$(NO_C)"

re: fclean all
	@printf "$(WHITE)[En Taro Tassadar]$(NO_C)"

norme:
	@norminette ./sources/
	@norminette ./includes/
