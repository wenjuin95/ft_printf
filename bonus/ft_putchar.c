/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:02:50 by welow             #+#    #+#             */
/*   Updated: 2023/10/30 00:18:46 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_flag(char c, t_flag *flags)
{
	int	count;

	count = 0;
	if (flags->minus == 1)
	{
		count += ft_putchar(c);
		while (flags->width > 1)
		{
			count += ft_putchar(' ');
			flags->width--;
		}
	}
	else
	{
		while (flags->width > 1)
		{
			count += ft_putchar(' ');
			count += ft_putchar(c);
			flags->width--;
		}
	}
	return (count);
}
