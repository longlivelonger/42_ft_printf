/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:54:57 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/05 18:30:28 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	flags_on;
}	t_flags;

int	ft_printf(const char *s, ...);

int	print_unsigned(unsigned int n, int fd);
int	print_hex(unsigned int n, int to_upper, int fd);
int	print_long_hex(unsigned long n, int to_upper, int fd);
int	print_addr(void *n, int fd);
int	print_arg(const char *s, int *i, va_list ap);

int	print_str(char *s, int fd);
int	print_num(int n, int fd);

#endif