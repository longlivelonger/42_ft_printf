/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:10:57 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/09 01:58:46 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_string(char c, char *s)
{
	char	*new_str;
	char	*temp;

	new_str = malloc(2 * sizeof(*new_str));
	if (new_str == 0)
		return (0);
	new_str[0] = c;
	new_str[1] = '\0';
	if (s == 0)
		s = new_str;
	else
	{
		temp = ft_strjoin(new_str, s);
		free(new_str);
		free(s);
		s = temp;
	}
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
	s = make_string(c, s);
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
		s = make_string('-', s);
	return (s);
}
