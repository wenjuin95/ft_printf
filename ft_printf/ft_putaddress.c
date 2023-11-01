/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:49:22 by welow             #+#    #+#             */
/*   Updated: 2023/11/01 21:56:17 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexa_ull(unsigned long long nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_puthexa_ull(nb / 16);
		count += ft_puthexa_ull(nb % 16);
	}
	else
	{
		if (nb < 10)
			count += ft_putchar(nb + '0');
		else
			count += ft_putchar(nb - 10 + 'a');
	}
	return (count);
}

int	ft_putaddress(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_puthexa_ull(ptr);
	return (count);
}
