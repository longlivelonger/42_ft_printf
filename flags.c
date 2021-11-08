/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 02:21:02 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/09 02:50:03 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(char *s, int i, t_flags *flags)
{
	while (ft_strchr("# +-0", s[i]))
	{
		if (s[i] == '#')
			flags->sharp = 1;
		else if (s[i] == ' ')
			flags->space = 1;
		else if (s[i] == '-')
			flags->minus = 1;
		else if (s[i] == '+')
			flags->plus = 1;
		else if (s[i] == '0')
			flags->zero = 1;
		i++;
	}
	while (ft_isdigit(s[i]))
		flags->min_width += flags->min_width * 10 + s[i++] - '0';
	if (s[i] == '.')
		flags->precision = 0;
	i++;
	while (ft_isdigit(s[i]))
		flags->precision += flags->precision * 10 + s[i++] - '0';
	flags->flags_parsed = 1;
}
