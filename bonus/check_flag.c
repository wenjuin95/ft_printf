/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:03:14 by welow             #+#    #+#             */
/*   Updated: 2023/10/29 00:28:29 by welow            ###   ########.fr       */
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
	int		i;

	format = "cspdiuxX%";
	i = 0;
	while (format[i])
	{
		if (format[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	input(char *format, int *i)
{
	int	count;

	count = ft_itoa(format + *i);
	while (ft_isdigit(format[*i]))
		(*i)++;
}

void	check_flags(char *str, int *i, t_flag *flags)
{
	while ((!(check_is_fs(str[*i]))) && str[*i])
	{
		if (ft_isdigit(str[*i]) && str[*i] != '0')
		{
			flags->width = input(str, i);
			continue ;
		}
		if (str[*i] == '0')
			flags->zero = 1;
		else if (str[*i] == '-')
			flags->minus = 1;
		else if (str[*i] == '.' && ((*i) + 1))
		{
			flags->dot = 1;
			flags->precision = input(str, i);
		}
		else if (str[*i] == '#')
			flags->hash = 1;
		else if (str[*i] == ' ')
			flags->space = 1;
		else if (str[*i] == '+')
			flags->plus = 1;
		(*i)++;
	}
}
