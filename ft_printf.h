/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:54:57 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/09 01:54:29 by sbronwyn         ###   ########.fr       */
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

int		ft_printf(const char *s, ...);

char	*get_unsigned(unsigned int n, char *s);
char	*get_hex(unsigned int n, int to_upper, char *s);
char	*get_long_hex(unsigned long n, int to_upper, char *s);
int		print_addr(void *n, int fd);
int		print_arg(const char *s, int *i, va_list ap);

char	*make_string(char c, char *s);
int		print_str(char *s, int fd);
char	*get_num(int n, char *s);

#endif