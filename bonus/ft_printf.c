/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:41:11 by welow             #+#    #+#             */
/*   Updated: 2023/10/27 21:00:18 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list_arg;
	int		char_print;
	int		i;
	t_flag	*flags;

	va_start(list_arg, format);
	char_print = 0;
	i = 0;
	flags = malloc(sizeof(t_flag));
	if (flags == NULL)
		return (NULL);
	while (format[i])
	{
		define_flag(flags);
		if (format[i] == '%')
		{
			check_flag(format, &i, flags);
			if (flags->zero == 1)
				flags->c = '0';
			char_print += printf_format(list_arg, format[i + 1]);
			i++;
		}
		else
			char_print += ft_putchar(format[i]);
		i++;
	}
	va_end(list_arg);
	return (char_print);

}