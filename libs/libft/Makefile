# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 14:14:45 by vangirov          #+#    #+#              #
#    Updated: 2022/05/05 21:11:45 by vangirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Your Makefile must at least contain rules $(NAME), all, clean, fclean and re
# To turn in bonuses to your project, you must include rule bonus to Makefile

#### VARS ####
CC = gcc

CFLAGS = -Wall -Werror -Wextra

ARFLAGS = rcs

NAME = libft.a

# filter-out removes any words that do not match the pattern
# OBJS = $(patsubst %.c,%.o,$(filter-out ft_l*, $(wildcard *.c)))
SRCS =	ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_toupper.c ft_tolower.c \
		ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_strnstr.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_atoi.c \
		ft_memmove.c ft_memcmp.c ft_memchr.c \
		ft_memset.c ft_memcpy.c ft_bzero.c \
		ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c get_next_line.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c

OBJS = $(SRCS:.c=.o)

BONUSOBJS = $(OBJS) $(BONUS:.c=.o)

#### RULES ####
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(BONUSOBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS) $(BONUSOBJS)

clean:
	rm -f $(wildcard *.o)

fclean: clean
	rm -f $(NAME)

re: fclean all