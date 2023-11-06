/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:02:50 by welow             #+#    #+#             */
/*   Updated: 2023/11/06 18:52:41 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_minus(char c, t_flag *flags)
{
	int	count;

	count = 0;
	if (!(flags->minus))
	{
		while (flags->width > 1)
		{
			count += ft_putchar(' ');
			flags->width--;
		}
		count += (ft_putchar(c));
		return (count);
	}
	else
	{
		count += (ft_putchar(c));
		while (flags->width > 1)
		{
			count += ft_putchar(' ');
			flags->width--;
		}
		return (count);
	}
}

int	ft_putchar_flag(char c, t_flag *flags)
{
	int	count;

	count = 0;
	if (flags->width > 1)
		count += (ft_putchar_minus(c, flags));
	else
		count += (ft_putchar(c));
	return (count);
}