# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 21:02:22 by sbronwyn          #+#    #+#              #
#    Updated: 2021/11/10 19:19:37 by sbronwyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c utils.c utils2.c utils3.c utils4.c flags.c

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

bonus: all

$(LIBFT):
	$(MAKE_LIBFT) bonus

.PHONY: all re clean fclean bonus