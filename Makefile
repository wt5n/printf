# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 15:45:02 by ksenaida          #+#    #+#              #
#    Updated: 2020/03/03 17:42:18 by hlikely          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC1 = adv_itoa.c ap_arith.c parsing.c ft_printf.c type_other.c\
	type_c.c type_di.c type_di_add.c add_func.c handling_f.c \
	type_f.c type_s.c type_u.c type_x.c type_p.c type_o.c type_f_add.c \
	type_b.c handling_lf.c

OBJ1 = adv_itoa.o ap_arith.o parsing.o ft_printf.o type_other.o\
	type_c.o type_di.o type_di_add.o add_func.o handling_f.o \
	type_f.o type_s.o type_u.o type_x.o type_p.o type_o.o type_f_add.o \
	type_b.o handling_lf.o

HDR = printf.h
LIBFT = libft/
FLAGS = -Wall -Wextra -Werror
LIBFTO = ./libft/*.o

all: $(NAME)

$(NAME): $(OBJ1) $(SRC1) $(LIBFT) $(HDR)
	make -C $(LIBFT)
	ar rc $(NAME) $(OBJ1) $(LIBFTO)

%.o:%.c
	gcc -c -Wall -Wextra -Werror -I$(HDR) $<

clean:
	rm -rf $(OBJ1)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
