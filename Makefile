# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/13 16:44:11 by tferrari          #+#    #+#              #
#    Updated: 2017/09/19 15:51:13 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft

ASM = asm

VM = vm

all : libft
	@make -C $(VM)
	@make -C $(ASM)

libft:
	@make -C libft
	@printf "$(GREEN)[/!\ libft READY /!\]$(NO_C)\n"

clean:
	@make -C libft clean
	@make -C $(VM) clean
	@make -C $(ASM) clean

fclean:
	@make -C libft fclean
	@make -C $(VM) fclean
	@make -C $(ASM) fclean

re: fclean all

norme:
	@make norme -C libft
	@make norme -C $(ASM)
	@make norme -C $(VM)
