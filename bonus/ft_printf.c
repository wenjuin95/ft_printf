/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wenjuin <wenjuin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:41:11 by welow             #+#    #+#             */
/*   Updated: 2023/10/29 16:03:04 by wenjuin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_printf(const char *format, ...)
{
    va_list	list_arg;
    int		i;
    int		char_print;
	t_flag	*flags;

	i = 0;
	char_print = 0;
	va_start(list_arg, format);
	while (format[i])
	{
		define_flags(flags);
		if (format[i] == '%')
		
	}
}
