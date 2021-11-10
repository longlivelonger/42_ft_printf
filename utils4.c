/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:28:04 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/10 17:38:53 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_zero(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] == '0')
		i++;
	return (s[i] == '\0');
}

char	*prepend_chars(char *s, char c, size_t len)
{
	while (ft_strlen(s) < len)
		s = prepend_char(c, s);
	return (s);
}

char	*append_chars(char *s, char c, size_t len)
{
	while (ft_strlen(s) < len)
		s = append_char(c, s);
	return (s);
}

char	*prepend_zeros_neg(char *s, size_t digits_count)
{
	char	temp;

	while (ft_strlen(s) < digits_count + 1)
	{
		s = prepend_char('0', s);
		temp = s[0];
		s[0] = s[1];
		s[1] = temp;
	}
	return (s);
}

char	*cut_string(char *s, size_t precision)
{
	if (ft_strlen(s) > precision)
		s[precision] = '\0';
	return (s);
}
