/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:41:11 by welow             #+#    #+#             */
/*   Updated: 2023/11/06 19:32:34 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(va_list list_arg, const char format, t_flag *flags)
{
	int		count;

	count = 0;
	if (format == 'c')
		count += ft_putchar_flag(va_arg(list_arg, int), flags);
	else if (format == 's')
		count += ft_putstr_flag(va_arg(list_arg, char *), flags);
	// else if (format == 'd' || format == 'i')
	// 	count += ft_putnbr(va_arg(list_argument, int));
	// else if (format == 'u')
	// 	count += ft_putnbr_unsigned(va_arg(list_argument, unsigned int));
	// else if (format == 'x')
	// 	count += ft_puthexa_lower(va_arg(list_argument, unsigned int));
	// else if (format == 'X')
	// 	count += ft_puthexa_upper(va_arg(list_argument, unsigned int));
	// else if (format == 'p')
	// 	count += ft_putaddress(va_arg(list_argument, unsigned long long));
	// else if (format == '%')
	// 	count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		list_arg;
	int			i;
	int			count;
	t_flag		flags;

	i = 0;
	count = 0;
	va_start(list_arg, format);
	while (format[i])
	{
		define_flags(&flags);
		if (format[i] == '%')
		{
			i = check_flags(format, i, &flags);
			count += print_format(list_arg, format[i], &flags);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(list_arg);
	return (count);
}
