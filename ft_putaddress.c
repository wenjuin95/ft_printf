/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:10:30 by welow             #+#    #+#             */
/*   Updated: 2023/10/26 21:43:31 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_pointer(unsigned long pointer)
// {
// 	char	*str;
// 	int		i;
// 	char	*base;

// 	str = malloc(18 * sizeof(char));
// 	base = "0123456789abcdef";
// 	i = 0;
// 	write(1, "0x", 2);
// 	if (pointer == 0)
// 	{
// 		ft_putchar('0');
// 	}
// 	while (pointer != 0)
// 	{
// 		str[i++] = base[pointer % 16];
// 		pointer /= 16;
// 		i++;
// 	}
// 	while (i--)
// 		return (ft_putchar(str[i]));
// }


int	ft_putaddress(unsigned long long n, int base)
{
	int		count;
	char	*symbol;

	symbol = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbr_base(-n, base) + 1);
	}
	else if (n < (unsigned long long)base)
		return (ft_putchar(symbol[n]));
	else
	{
		count = ft_putnbr_base(n / (unsigned long long)base, base);
		return (count + ft_putnbr_base(n % (unsigned long long)base, base));
	}
}