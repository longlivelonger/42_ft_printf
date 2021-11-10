/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:32:39 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/10 19:00:17 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str(char *s)
{
	if (s == 0)
		return (prepend_str("(null)", 0));
	return (ft_strdup(s));
}

int	print_str(char *s, char c, t_flags *flags, int fd)
{
	int	len;

	if (s == 0)
		return (0);
	s = apply_flags(s, c, flags);
	len = ft_strlen(s);
	if (c == 'c' && flags->len_plus_one && flags->minus)
		write(fd, "\0", 1);
	write(fd, s, len);
	if (c == 'c' && flags->len_plus_one && !flags->minus)
		write(fd, "\0", 1);
	free(s);
	return (len + flags->len_plus_one);
}
