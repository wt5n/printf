# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 15:45:02 by ksenaida          #+#    #+#              #
#    Updated: 2020/02/22 18:21:44 by ksenaida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC1 = adv_itoa.c ap_arith.c parsing.c ft_printf.c \
	length.c type_c.c type_d_and_i.c ft_put_cow.c handling_f.c \
	type_f_and_F.c type_str.c type_u.c type_xX.c type_p.c type_o.c

OBJ1 = adv_itoa.o ap_arith.o parsing.o ft_printf.o \
	length.o type_c.o type_d_and_i.o ft_put_cow.o handling_f.o \
	type_f_and_F.o type_str.o type_u.o type_xX.o type_p.o type_o.o

HDR = printf.h
LIBFT = libft/
FLAGS = -Wall -Wextra -Werror
LIBFTO = ./libft/*.o

all: $(NAME)

$(NAME):
		make -C $(LIBFT)
		gcc $(FLAGS) -c $(SRC1) -I $(HDR)
		ar rc $(NAME) $(OBJ1) $(LIBFTO)

clean:
	rm -rf $(OBJ1)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re