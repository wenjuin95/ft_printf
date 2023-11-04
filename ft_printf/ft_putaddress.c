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
	else if (nb <= 16)
	{
		count += write(1, "0123456789abcdef" + nb, 1);
	}
	return (count);
}

int	ft_putaddress(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_puthexa_ull(ptr);
	return (count);
}
