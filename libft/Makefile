# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manualva <manualva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 10:59:31 by manualva          #+#    #+#              #
#    Updated: 2024/05/08 12:03:22 by manualva         ###   ########.fr        #
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

#SRCS = $(shell find . -iname 'ft_*.c' -exec basename {} \;)

BSRCS = \
ft_lstnew_bonus.c		ft_lstadd_front_bonus.c		ft_lstsize_bonus.c			\
ft_lstlast_bonus.c		ft_lstadd_back_bonus.c		ft_lstdelone_bonus.c		\
ft_lstclear_bonus.c		ft_lstiter_bonus.c			ft_lstmap_bonus.c

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