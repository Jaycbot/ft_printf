# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 00:25:15 by jaehchoi          #+#    #+#              #
#    Updated: 2021/01/22 21:43:52 by jaehchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft
LIBA = libft.a
SRCS = ./c_parse.c \
	   				./ft_printf_utils.c \
					./ft_printf_utils2.c \
					./parse_common.c \
					./s_parse.c \
					./x_parse.c \
					./ft_printf.c \
					./perc_parse.c \
					./u_int.c \
					./x_parse_pt.c \
					./i_int.c \
					./p_parse.c \
					./u_parse.c \
					./i_parse.c \
					./p_parse_pt.c \
					./s_no_pre.c \
					./utf_8.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/$(LIBA) $(NAME)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
re: fclean all

.PHONY: all fclean clean bonus re
