/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:56:21 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/05 18:30:15 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	empty_flags(t_flags *flags)
{
	flags->flags_on = 0;
}

static void	incr_hook(int count, int *count_ptr, t_flags *flags, char c)
{
	*count_ptr = *count_ptr + count;
	if (ft_strchr("cspdiuxX%", c))
		empty_flags(flags);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;
	t_flags	flags;

	if (s == 0)
		return (-1);
	va_start(ap, s);
	empty_flags(&flags);
	count = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (flags.flags_on && ft_strchr("cspdiuxX%# +-0.", s[i]))
			incr_hook(print_arg(s, &i, ap), &count, &flags, s[i]);
		else if (s[i] == '%')
			flags.flags_on = 1;
		else
		{
			ft_putchar_fd(s[i], 1);
			incr_hook(1, &count, &flags, s[i]);
		}
	}
	va_end(ap);
	return (count);
}
