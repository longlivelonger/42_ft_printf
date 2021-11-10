/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 02:21:02 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/10 19:10:59 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(char *s, int i, t_flags *flags)
{
	while (ft_strchr("# +-0", s[i]))
	{
		if (s[i] == '#')
			flags->sharp = 1;
		else if (s[i] == ' ')
			flags->space = 1;
		else if (s[i] == '-')
			flags->minus = 1;
		else if (s[i] == '+')
			flags->plus = 1;
		else if (s[i] == '0')
			flags->zero = 1;
		i++;
	}
	while (ft_isdigit(s[i]))
		flags->min_width = flags->min_width * 10 + s[i++] - '0';
	if (s[i] == '.')
		flags->precision = 0;
	i++;
	while (ft_isdigit(s[i]))
		flags->precision = flags->precision * 10 + s[i++] - '0';
	flags->flags_parsed = 1;
}

static int	is_sign(char c)
{
	return (c == '-' || c == '+' || c == ' ');
}

static char	*apply_flags_part2(char *s, char c, t_flags *flags)
{
	if (flags->sharp && c == 'x' && !is_zero(s)
		&& flags->min_width > ft_strlen(s) + 2)
		s = prepend_str("0x", prepend_chars(s, '0', flags->min_width - 2));
	else if (flags->zero && c == '%' && !is_sign(s[0]) && !flags->minus
		&& flags->precision == -1 && flags->min_width > 0)
		s = prepend_chars(s, '0', flags->min_width);
	else if (flags->zero && ft_strchr("diuxX", c) && !is_sign(s[0])
		&& flags->precision == -1 && flags->min_width > 0)
		s = prepend_chars(s, '0', flags->min_width);
	else if (flags->zero && ft_strchr("di", c) && is_sign(s[0])
		&& flags->precision == -1 && flags->min_width > 0)
		s = prepend_zeros_neg(s, flags->min_width - 1);
	if (c == 'c' && s[0] == '\0')
		flags->len_plus_one = 1;
	if (flags->min_width > 0 && !flags->minus)
		s = prepend_chars(s, ' ', flags->min_width - flags->len_plus_one);
	else if (flags->min_width > 0 && flags->minus)
		s = append_chars(s, ' ', flags->min_width - flags->len_plus_one);
	return (s);
}

char	*apply_flags(char *s, char c, t_flags *flags)
{
	if (flags->plus && ft_strchr("di", c) && ft_isdigit(s[0]))
		s = prepend_char('+', s);
	else if (flags->space && ft_strchr("di", c) && ft_isdigit(s[0]))
		s = prepend_char(' ', s);
	if (flags->precision > 0 && ft_strchr("diuxX", c) && !is_sign(s[0]))
		s = prepend_chars(s, '0', (size_t)flags->precision);
	else if (flags->precision > 0 && ft_strchr("di", c) && is_sign(s[0]))
		s = prepend_zeros_neg(s, (size_t)flags->precision);
	else if (flags->precision >= 0 && c == 's')
		s = cut_string(s, (size_t)flags->precision);
	if (flags->sharp && c == 'x' && !is_zero(s)
		&& flags->min_width <= ft_strlen(s) + 2)
		s = prepend_str("0x", s);
	else if (flags->sharp && c == 'X' && !is_zero(s)
		&& flags->min_width <= ft_strlen(s) + 2)
		s = prepend_str("0X", s);
	if (flags->precision == 0 && ft_strchr("diuxX", c) && is_zero(s))
		s[0] = '\0';
	s = apply_flags_part2(s, c, flags);
	return (s);
}
