/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:43:58 by welow             #+#    #+#             */
/*   Updated: 2023/11/01 21:56:42 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_upper(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_puthexa_upper(nb / 16);
		count += ft_puthexa_upper(nb % 16);
	}
	else if (nb <= 16)
		count += write(1, "0123456789ABCDEF" + nb, 1);
	return (count);
}
