# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/13 16:44:11 by tferrari          #+#    #+#              #
#    Updated: 2017/09/19 15:51:47 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft

NAME = corewar

SRC_DIR = sources

SRC_FILE =	add.c aff.c and_ft.c battle.c debug.c fork.c getset_memory.c \
			intchar.c ld.c ldi.c lfork.c live.c lld.c lldi.c loadbots.c \
			loadfunc.c loadmemory.c main.c open.c or_ft.c print_memory.c \
			process.c st.c sti.c sub.c xor_ft.c zjmp.c check_ocp.c stun.c \
			view.c showprocess.c getcommand.c showview.c controls.c \
			getset_registre.c sound.c getcommand2.c help.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJS_DIR = obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_FILE:.c=.o))

INC = -I ../libft/includes -I ./includes

LFT = -L ../libft -lft

all : $(NAME)

$(NAME): $(OBJS)
	@gcc -Wall -Werror -Wextra $(LFT) -lncurses -o $(NAME) $(OBJS)
	@echo "\033[32mexecutable corewar créé\033[0m"

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@gcc -Wall -Werror -Wextra $(INC) -o $@ -c $<
	@echo "Fichier" $< "recompilé."

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\033[31mFichier objet de corewar supprimé\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mcorewar supprimé\033[0m"

re: fclean all

norme:
	@norminette ./sources/
	@norminette ./includes/
