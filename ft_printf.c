/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:56:21 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/10/19 17:57:18 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	increment_hook(int count, int *count_ptr, int *start_of_placeholder)
{
	*count_ptr = *count_ptr + count;
	*start_of_placeholder = 0;
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		start_of_placeholder;

	if (s == 0)
		return (-1);
	va_start(ap, s);
	start_of_placeholder = 0;
	count = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (start_of_placeholder && ft_strchr("cspdiuxX%", s[i]))
			increment_hook(print_arg(s[i], ap), &count, &start_of_placeholder);
		else if (s[i] == '%')
			start_of_placeholder = 1;
		else
		{
			ft_putchar_fd(s[i], STDOUT_FILENO);
			increment_hook(1, &count, &start_of_placeholder);
		}
	}
	va_end(ap);
	return (count);
}
