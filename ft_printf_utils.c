/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:25:14 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/10/19 15:48:23 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n, int fd)
{
	unsigned int	digit;
	char			c;
	int				count;

	count = 0;
	digit = n % 10;
	c = '0' + digit;
	if (n >= 10)
		count += print_unsigned(n / 10, fd);
	write(fd, &c, 1);
	return (count + 1);
}

int	print_hex(unsigned int n, int to_upper, int fd)
{
	unsigned int	digit;
	char			c;
	int				count;

	count = 0;
	digit = n % 16;
	c = '0' + digit;
	if (digit >= 10)
		c = 'a' + digit - 10;
	if (to_upper)
		c = ft_toupper(c);
	if (n >= 16)
		count += print_hex(n / 16, to_upper, fd);
	write(fd, &c, 1);
	return (count + 1);
}

int	print_long_hex(unsigned long n, int to_upper, int fd)
{
	unsigned long	digit;
	char			c;
	int				count;

	count = 0;
	digit = n % 16;
	c = '0' + digit;
	if (digit >= 10)
		c = 'a' + digit - 10;
	if (to_upper)
		c = ft_toupper(c);
	if (n >= 16)
		count += print_long_hex(n / 16, to_upper, fd);
	write(fd, &c, 1);
	return (count + 1);
}

int	print_addr(void *n, int fd)
{
	write(fd, "0x", 2);
	return (print_long_hex((unsigned long)n, 0, fd) + 2);
}

int	print_arg(char c, va_list ap)
{
	if (c == '%')
		ft_putchar_fd('%', STDOUT_FILENO);
	else if (c == 'c')
		ft_putchar_fd((unsigned char)va_arg(ap, int), STDOUT_FILENO);
	else if (c == 's')
		return (print_str(va_arg(ap, char *), STDOUT_FILENO));
	else if (c == 'd' || c == 'i' || c == 'D')
		return (print_num(va_arg(ap, int), STDOUT_FILENO));
	else if (c == 'u')
		return (print_unsigned(va_arg(ap, unsigned int), STDOUT_FILENO));
	else if (c == 'p')
		return (print_addr(va_arg(ap, void *), STDOUT_FILENO));
	else if (c == 'x')
		return (print_hex(va_arg(ap, unsigned int), 0, STDOUT_FILENO));
	else if (c == 'X')
		return (print_hex(va_arg(ap, unsigned int), 1, STDOUT_FILENO));
	if (c == '%' || c == 'c')
		return (1);
	return (0);
}
