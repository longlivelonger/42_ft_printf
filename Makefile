# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 21:02:22 by sbronwyn          #+#    #+#              #
#    Updated: 2021/10/15 17:11:42 by sbronwyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c

MAKE_LIBFT = make -C libft
LIBFT = libft/libft.a

AR = ar rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(SRC:.c=.o)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(SRC:.c=.o)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(SRC:.c=.o) $(SRC_BONUS:.c=.o)
	$(MAKE_LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all

$(LIBFT):
	$(MAKE_LIBFT) bonus

.PHONY: all re clean fclean