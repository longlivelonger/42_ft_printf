/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:56:21 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/05 18:06:39 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	incr_hook(int count, int *count_ptr, int *start_of_flags)
{
	*count_ptr = *count_ptr + count;
	*start_of_flags = 0;
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		start_of_flags;

	if (s == 0)
		return (-1);
	va_start(ap, s);
	start_of_flags = 0;
	count = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (start_of_flags && ft_strchr("cspdiuxX%# +-0.", s[i]))
			incr_hook(print_arg((char *)(s + i), ap), &count, &start_of_flags);
		else if (s[i] == '%')
			start_of_flags = 1;
		else
		{
			ft_putchar_fd(s[i], STDOUT_FILENO);
			incr_hook(1, &count, &start_of_flags);
		}
	}
	va_end(ap);
	return (count);
}
