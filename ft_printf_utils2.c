/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:10:57 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/10/15 17:16:27 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s, int fd)
{
	if (s == 0)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	print_num(int n, int fd)
{
	int		digit;
	char	c;
	int		count;

	count = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		count++;
	}
	digit = n % 10;
	if (n < 0)
		digit *= -1;
	c = '0' + digit;
	if (n <= -10)
		count += print_num((n / 10) * -1, fd);
	if (n >= 10)
		count += print_num(n / 10, fd);
	write(fd, &c, 1);
	return (count + 1);
}
