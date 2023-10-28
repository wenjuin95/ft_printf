/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:03:14 by welow             #+#    #+#             */
/*   Updated: 2023/10/29 02:25:01 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	define_flags(t_flag *flags)
{
	bzero(flags, sizeof(t_flag));
}

int	check_is_fs(char c)
{
	char	*format;

	format = "cspdiuxX%";
	if (ft_strchr(format, c))
		return (1);
	return (0);
}

int	make_slot(const char *format, int i)
{
	int		count;

	count = 0;
	while (ft_isdigit(format[i]))
	{
		count += ft_atoi(format[i]);
		i++;
	}
	return (count);
}

int	check_flags(char *format, int i, t_flag *flags)
{
	while (check_is_fs(format[i]))
	{
		if (ft_isdigit(format[i]))
		{
			flags->width = make_slot(format, i);
			continue ;
		}
		else if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		else if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == '.' && i + 1)
		{
			flags->dot = 1;
			flags->precision = make_slot(format, i);
		}
		else if (format[i] == '#')
			flags->hash = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		i++;
	}
}
