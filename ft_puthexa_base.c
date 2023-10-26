/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:34:53 by welow             #+#    #+#             */
/*   Updated: 2023/10/26 17:58:50 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_puthexa(size_t pointer, char format)
// {
// 	char	*str;
// 	int		i;
// 	char	*base;

// 	str = malloc(16 * sizeof(char));
// 	if (str == NULL)
// 		return ;
// 	if (format == 'X')
// 		base = "0123456789ABCDEF";
// 	else
// 		base = "0123456789abcdef";
// 	i = 0;
// 	if (pointer == 0)
// 	{
// 		ft_putchar('0');
// 		return ;
// 	}
// 	while (pointer != 0)
// 	{
// 		str[i++] = base[pointer % 16];
// 		pointer /= 16;
// 		i++;
// 	}
// 	while (i--)
// 		ft_putchar(str[i]);
// }


int	ft_puthexa_base(long n, int base)
{
	int		count;
	char	*symbol;

	symbol = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_puthexa_base(-n, base) + 1);
	}
	else if (n < base)
		return (ft_putchar(symbol[n]));
	else
	{
		count = ft_puthexa_base(n / base, base);
		return (count + ft_puthexa_base(n % base, base));
	}
}