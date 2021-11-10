/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:10:57 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/10 14:24:40 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prepend_str(char *new_str, char *s)
{
	char	*temp;

	if (s == 0)
		s = ft_strdup(new_str);
	else
	{
		temp = ft_strjoin(new_str, s);
		free(s);
		s = temp;
	}
	return (s);
}

char	*prepend_char(char c, char *s)
{
	char	new_str[2];

	new_str[0] = c;
	new_str[1] = '\0';
	s = prepend_str((char *)&new_str, s);
	return (s);
}

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

char	*get_num_rec(int n, char *s)
{
	int		digit;
	char	c;

	digit = n % 10;
	if (n < 0)
		digit *= -1;
	c = '0' + digit;
	s = prepend_char(c, s);
	if (n <= -10)
		s = get_num_rec((n / 10) * -1, s);
	if (n >= 10)
		s = get_num_rec(n / 10, s);
	return (s);
}

char	*get_num(int n, char *s)
{
	if (s == 0)
		s = get_num_rec(n, s);
	if (n < 0)
		s = prepend_char('-', s);
	return (s);
}
