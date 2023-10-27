/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:15:50 by welow             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/27 14:27:13 by welow            ###   ########.fr       */
=======
/*   Updated: 2023/10/27 00:46:59 by welow            ###   ########.fr       */
>>>>>>> bd2747d10ee513f69bc9a8d96520769c53b94c18
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_format(va_list list_argument, const char str)
{
	int		count;
	void	*ptr;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(list_argument, int));
	else if (str == 's')
		count += ft_putstr(va_arg(list_argument, char *));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(list_argument, int));
	else if (str == 'u')
		count += ft_putnbr_unsigned(va_arg(list_argument, unsigned int));
	else if (str == 'x')
<<<<<<< HEAD
		count += ft_puthexa_lower(va_arg(list_argument, unsigned int));
	else if (str == 'X')
		count += ft_puthexa_upper(va_arg(list_argument, unsigned int));
=======
		count += ft_puthexa_base(va_arg(list_argument, unsigned int), 16, 0);
	else if (str == 'X')
		count += ft_puthexa_base(va_arg(list_argument, unsigned int), 16, 1);
	else if (str == 'u')
		count += ft_putnbr_base(va_arg(list_argument, unsigned int), 10);
>>>>>>> bd2747d10ee513f69bc9a8d96520769c53b94c18
	else if (str == 'p')
		count += ft_putaddress(va_arg(list_argument, unsigned long long));
	else if (str == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		list_argument;
	int			i;
	int			char_print;

	i = 0;
	char_print = 0;
	va_start(list_argument, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_print += printf_format(list_argument, format[i + 1]);
			i++;
		}
		else
			char_print += ft_putchar(format[i]);
		i++;
	}
	va_end(list_argument);
	return (char_print);
}
