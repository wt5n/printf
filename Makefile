# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 15:45:02 by ksenaida          #+#    #+#              #
#    Updated: 2020/02/01 21:56:56 by hlikely          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = printf

SRC1 = adv_itoa.c ap_arith.c parsing.c ft_printf.c \
	handling_f.c length.c type_c.c type_d_and_i.c \
	type_f_and_F.c type_str.c type_u.c type_xX_and_o.c

OBJ1 = adv_itoa.o ap_arith.o parsing.o ft_printf.o \
	handling_f.o length.o type_c.o type_d_and_i.o \
	type_f_and_F.o type_str.o type_u.o type_xX_and_o.o

HDR = printf.h
LIBFT = libft/
FLAGS = -Wall -Wextra -Werror

all: $(NAME_PS)

$(NAME_PS):
		make -C $(LIBFT)
		gcc $(FLAGS) -o $(NAME_PS) $(SRC1) -I $(HDR) -L. libft/libft.a

clean:
	rm -rf $(OBJ1)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME_PS)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re