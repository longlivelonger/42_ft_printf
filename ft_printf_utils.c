/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:25:14 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/09 01:55:10 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_unsigned(unsigned int n, char *s)
{
	unsigned int	digit;
	char			c;

	digit = n % 10;
	c = '0' + digit;
	s = make_string(c, s);
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
	s = make_string(c, s);
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
	s = make_string(c, s);
	if (n >= 16)
		s = get_long_hex(n / 16, to_upper, s);
	return (s);
}

int	print_addr(void *n, int fd)
{
	write(fd, "0x", 2);
	return (print_str(get_long_hex((unsigned long)n, 0, 0), fd) + 2);
}

int	print_arg(const char *s, int *i, va_list ap)
{
	if (s[*i] == '%')
		ft_putchar_fd('%', 1);
	else if (s[*i] == 'c')
		ft_putchar_fd((unsigned char)va_arg(ap, int), 1);
	else if (s[*i] == 's')
		return (print_str(va_arg(ap, char *), 1));
	else if (s[*i] == 'd' || s[*i] == 'i' || s[*i] == 'D')
		return (print_str(get_num(va_arg(ap, int), 0), 1));
	else if (s[*i] == 'u')
		return (print_str(get_unsigned(va_arg(ap, unsigned int), 0), 1));
	else if (s[*i] == 'p')
		return (print_addr(va_arg(ap, void *), 1));
	else if (s[*i] == 'x')
		return (print_str(get_hex(va_arg(ap, unsigned int), 0, 0), 1));
	else if (s[*i] == 'X')
		return (print_str(get_hex(va_arg(ap, unsigned int), 1, 0), 1));
	if (s[*i] == '%' || s[*i] == 'c')
		return (1);
	return (0);
}
