# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manualva <manualva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 13:03:54 by manualva          #+#    #+#              #
#    Updated: 2024/05/13 11:32:28 by manualva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  \
ft_printf.c		ft_print_str.c	ft_print_ptr.c	ft_print_num.c	ft_print_uns.c	\
ft_print_hex.c

OBJS = $(SRCS:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
all: $(NAME)
$(NAME): $(OBJS)
	$(AR) -r $@ $?
%.o: %.c
	$(CC) -o $@ -c $(CFLAGS) $<
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re