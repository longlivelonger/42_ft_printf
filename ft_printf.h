/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:54:57 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/10 18:11:02 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int		flags_on;
	int		flags_parsed;
	int		sharp;
	int		space;
	int		minus;
	int		plus;
	int		zero;
	size_t	min_width;
	int		precision;
	size_t	len_plus_one;
}	t_flags;

int		ft_printf(const char *s, ...);

char	*get_unsigned(unsigned int n, char *s);
char	*get_hex(unsigned int n, int to_upper, char *s);
char	*get_long_hex(unsigned long n, int to_upper, char *s);
char	*get_addr(void *n);
int		print_arg(const char *s, int *i, va_list ap, t_flags *flags);

char	*prepend_str(char *new_str, char *s);
char	*prepend_char(char c, char *s);
char	*append_char(char c, char *s);
char	*get_num(int n, char *s);

char	*get_str(char *s);
int		print_str(char *s, char c, t_flags *flags, int fd);

void	parse_flags(char *s, int i, t_flags *flags);
char	*apply_flags(char *s, char c, t_flags *flags);

int		is_zero(char *s);
char	*prepend_chars(char *s, char c, size_t len);
char	*append_chars(char *s, char c, size_t len);
char	*prepend_zeros_neg(char *s, size_t digits_count);
char	*cut_string(char *s, size_t precision);

#endif