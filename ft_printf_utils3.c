/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:32:39 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/10 14:41:44 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str(char *s)
{
	if (s == 0)
		return (prepend_str("(null)", 0));
	return (ft_strdup(s));
}
