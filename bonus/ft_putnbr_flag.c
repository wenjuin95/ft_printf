/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:11:39 by welow             #+#    #+#             */
/*   Updated: 2023/11/06 22:02:51 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_flag(int n, t_flag *flags)
{
	char	*str;
	int		count;
	int		i;
	char	*tmp;
	
	count = 0;
	str = ft_itoa(n);
	if (flags->plus && n > 0)
		count += ft_putchar('+');
	if (flags->zero && flags->width > ft_strlen(str))
	{
		i = 0;
		while(i < flags->width-ft_strlen(str))
		{
			count += ft_putchar('0');
			i++;
		}
	}
}



