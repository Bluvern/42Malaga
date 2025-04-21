# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manualva <manualva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 10:59:31 by manualva          #+#    #+#              #
#    Updated: 2024/08/06 12:03:49 by manualva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  \
ft_isalpha.c    ft_isdigit.c    ft_isascii.c    ft_isalnum.c    ft_isprint.c    \
ft_strlen.c     ft_toupper.c    ft_tolower.c    ft_strlcpy.c    ft_strlcat.c    \
ft_atoi.c       ft_strchr.c     ft_strncmp.c    ft_memset.c     ft_memmove.c    \
ft_bzero.c      ft_memcpy.c     ft_memcpy.c     ft_memcmp.c     ft_memchr.c     \
ft_calloc.c     ft_strrchr.c    ft_strnstr.c    ft_strdup.c     ft_itoa.c       \
ft_substr.c     ft_strjoin.c    ft_strtrim.c    ft_split.c      ft_strmapi.c    \
ft_striteri.c   ft_putstr_fd.c  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c  \
ft_lstnew.c			ft_lstadd_front.c		ft_lstsize.c		ft_lstlast.c	\
ft_lstadd_back.c	ft_lstdelone.c			ft_lstclear.c		ft_lstiter.c	\
ft_lstmap.c																		\
ft_printf.c		ft_print_str.c	ft_print_ptr.c	ft_print_num.c	ft_print_uns.c	\
ft_print_hex.c																	\
ft_get_next_line.c																\
ft_isupper.c			ft_islower.c				ft_isnegative.c				\
ft_swap.c				ft_rev_int_tab.c			ft_str_is_alpha.c			\
ft_str_is_numeric.c		ft_str_is_uppercase.c		ft_str_is_lowercase.c		\
ft_str_is_printable.c	ft_strupcase.c				ft_strlowcase.c				\
ft_strcmp.c				ft_putchar.c				ft_strcspn.c				\

BSRCS = \

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
all: $(NAME)
bonus: $(BOBJS)
	$(AR) -r $(NAME) $?
$(NAME): $(OBJS)
	$(AR) -r $@ $?
%.o: %.c
	$(CC) -o $@ -c $(CFLAGS) $<
clean:
	rm -f $(OBJS) $(BOBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all bonus clean fclean re
#progress_bar:
#	printf "["
#	for i in (seq 1 50); do \
#		sleep 0.1; \
#		printf "\033[0,91m█"; \
#	done
#	@printf"\033[0m]
#	@echo ""