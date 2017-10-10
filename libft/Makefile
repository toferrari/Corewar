# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 13:19:50 by mdeglain          #+#    #+#              #
#    Updated: 2017/08/01 16:54:58 by dbischof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAG = -Wall -Wextra -Werror -fsanitize=address

SRC_NAME =	$(sort ft_memset.c ft_bzero.c ft_memccpy.c ft_memcpy.c \
		ft_memcpy_bwd.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c \
		ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
		ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isupper.c ft_islower.c ft_isascii.c ft_isprint.c ft_toupper.c \
		ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
		ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		ft_itoa.c ft_putchar.c ft_putstr.c ft_putnstr.c \
		ft_putendl.c ft_putnbr.c ft_putllnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd.c ft_lstdelone.c \
		ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_putnbrendl.c ft_max.c ft_min.c \
		ft_sqrt.c ft_dsqrt.c ft_piapprox.c ft_r_factorial.c ft_power.c \
		ft_putwchar_fd.c ft_putwchar.c ft_putwstr.c ft_putnwstr.c ft_nblen.c \
		ft_strrev.c ft_base.c ft_baselen.c ft_wstrlen.c ft_wcharlen.c \
		ft_printn_char.c ft_wnstrlen.c ft_abs.c ft_is_space.c \
		ft_strisdigit.c ft_lstaddafter.c ft_nbchr.c ft_printf.c parsing.c \
		conversion.c pct_conv.c p_conv.c min_w.c s_conv.c upper_conv.c \
		di_conv.c o_conv.c u_conv.c x_conv.c c_conv.c utils.c b_conv.c \
		ft_strchrindex.c my_fgets.c my_fopen.c my_fclose.c my_fgetc.c \
		get_next_line.c my_strtoull.c my_strtoll.c my_strtoul.c my_strtol.c \
		my_strtouint.c my_strtoint.c \
		ft_strsplit.c ft_strsplit_free.c ft_strsplit_len.c )

SRC_PATH = ./src/
OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_PATH = ./includes/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

.PHONY: all libft clean fclean re norme

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norme:
	@clear
	@norminette ./src/*.c
	@norminette ./includes/*.h
