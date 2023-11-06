/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:55:37 by welow             #+#    #+#             */
/*   Updated: 2023/11/06 20:04:42 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, int count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		count += (write(1, "(null)", 6));
		return (count);
	}
	else
	{
		while (str[i] && (i < count))
			i++;
		count += (write(1, str, i));
		return (count);
	}	
}

int	ft_pustr_minus(char *str, int string_len, t_flag *flags)
{
	int	count;

	count = 0;
	if (!(flags->minus))
	{
		while (flags->width > string_len)
		{
			count += ft_putchar(' ');
			flags->width--;
		}
		count += (ft_putstr(str, (string_len - count)));
		return (count);
	}
	else
	{
		count += (ft_putstr(str, (string_len - count)));
		while (flags->width > string_len)
		{
			count += ft_putchar(' ');
			flags->width--;
		}
		return (count);
	}
}

int	ft_putstr_flag(char *str, t_flag *flags)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	if (flags->dot)
	{
		if (flags->width > flags->precision)
			count = (ft_pustr_minus(str, flags->precision, flags));
		else
			count += (ft_putstr(str, flags->precision));
	}
	else if (!(flags->dot))
	{
		if (flags->width > ft_strlen(str))
			count += (ft_pustr_minus(str, ft_strlen(str), flags));
		else
			count += (ft_putstr(str, ft_strlen(str)));
	}
	return (count);
}