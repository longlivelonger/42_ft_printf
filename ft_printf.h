/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:54:57 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/10/15 17:11:29 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

int	ft_printf(const char *s, ...);

int	print_unsigned(unsigned int n, int fd);
int	print_hex(unsigned int n, int to_upper, int fd);
int	print_long_hex(unsigned long n, int to_upper, int fd);
int	print_addr(void *n, int fd);
int	print_arg(char c, va_list ap);

int	print_str(char *s, int fd);
int	print_num(int n, int fd);

#endif