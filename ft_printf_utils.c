/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:25:14 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/10 14:51:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_unsigned(unsigned int n, char *s)
{
	unsigned int	digit;
	char			c;

	digit = n % 10;
	c = '0' + digit;
	s = prepend_char(c, s);
	if (n >= 10)
		s = get_unsigned(n / 10, s);
	return (s);
}

char	*get_hex(unsigned int n, int to_upper, char *s)
{
	unsigned int	digit;
	char			c;

	digit = n % 16;
	c = '0' + digit;
	if (digit >= 10)
		c = 'a' + digit - 10;
	if (to_upper)
		c = ft_toupper(c);
	s = prepend_char(c, s);
	if (n >= 16)
		s = get_hex(n / 16, to_upper, s);
	return (s);
}

char	*get_long_hex(unsigned long n, int to_upper, char *s)
{
	unsigned long	digit;
	char			c;

	digit = n % 16;
	c = '0' + digit;
	if (digit >= 10)
		c = 'a' + digit - 10;
	if (to_upper)
		c = ft_toupper(c);
	s = prepend_char(c, s);
	if (n >= 16)
		s = get_long_hex(n / 16, to_upper, s);
	return (s);
}

char	*get_addr(void *n)
{
	char	*str;

	str = get_long_hex((unsigned long)n, 0, 0);
	str = prepend_str("0x", str);
	return (str);
}

int	print_arg(const char *s, int *i, va_list ap, t_flags *flags)
{
	char	*str;

	str = 0;
	if (ft_strchr("# +-.0123456789", s[*i]) && !flags->flags_parsed)
		parse_flags((char *)s, *i, flags);
	else if (s[*i] == '%')
		str = prepend_char('%', str);
	else if (s[*i] == 'c')
		str = prepend_char((unsigned char)va_arg(ap, int), str);
	else if (s[*i] == 's')
		str = get_str(va_arg(ap, char *));
	else if (s[*i] == 'd' || s[*i] == 'i' || s[*i] == 'D')
		str = get_num(va_arg(ap, int), 0);
	else if (s[*i] == 'u')
		str = get_unsigned(va_arg(ap, unsigned int), 0);
	else if (s[*i] == 'p')
		str = get_addr(va_arg(ap, void *));
	else if (s[*i] == 'x')
		str = get_hex(va_arg(ap, unsigned int), 0, 0);
	else if (s[*i] == 'X')
		str = get_hex(va_arg(ap, unsigned int), 1, 0);
	return (print_str(str, s[*i], 1));
}
