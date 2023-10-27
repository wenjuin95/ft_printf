/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:08:20 by welow             #+#    #+#             */
/*   Updated: 2023/10/27 14:15:11 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_lower(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_puthexa_lower(nb / 16);
		count += ft_puthexa_lower(nb % 16);
	}
	else
	{
		if (nb < 10)
			count += ft_putchar(nb + '0');
		else
			count += ft_putchar(nb + 87);
	}
	return (count);
}
