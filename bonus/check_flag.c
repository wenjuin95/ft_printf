/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:03:14 by welow             #+#    #+#             */
/*   Updated: 2023/11/06 18:51:59 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	define_flags(t_flag *flags)
{
	ft_bzero(flags, sizeof(t_flag));
}

int	check_is_fs(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i'
		|| c == 'p' || c == 'x' || c == 'X' || c == 'u'
		|| c == '%')
		return (1);
	return (0);
}

void	handle_digit(char c, t_flag *flags)
{
	if ('0' == c && !(flags->width) & !(flags->dot))
		flags->zero = 1;
	else if ('0' == c && flags->width && !(flags->dot))
		flags->width = (flags->width *= 10);
	else if ('0' == c && flags->dot)
		flags->precision = (flags->precision *= 10);
	else if (ft_isdigit((int)c))
	{
		if (!(flags->dot))
			flags->width = (flags->width * 10) + (c - 48);
		else if (flags->dot)
			flags->precision = (flags->precision * 10) + (c - 48);
	}
}

int	check_flags(const char *format, int i, t_flag *flags)
{
	char	is_flags;
	int		count;

	count = 0;
	while (!(check_is_fs(format[++i])))
	{
		is_flags = format[i];
		if (is_flags == '-')
			flags->minus = 1;
		else if (is_flags == '+')
			flags->plus = 1;
		else if (is_flags == '.')
			flags->dot = 1;
		else if (is_flags == '#')
			flags->hash = 1;
		else if (is_flags == ' ')
			flags->space = 1;
		else if (ft_isdigit(is_flags))
			handle_digit(is_flags, flags);
	}
	return (i);
}
