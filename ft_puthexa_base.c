/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:34:53 by welow             #+#    #+#             */
/*   Updated: 2023/10/27 00:47:47 by welow            ###   ########.fr       */
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


int	ft_puthexa_base(long n, int base, int is_upper)
{
	int		count;
	char	*symbol;

	if (is_upper)
		symbol = "0123456789ABCDEF";
	else
		symbol = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_puthexa_base(-n, base, is_upper) + 1);
	}
	else if (n < base)
		return (ft_putchar(symbol[n]));
	else
	{
		count = ft_puthexa_base(n / base, base, is_upper);
		return (count + ft_puthexa_base(n % base, base, is_upper));
	}
}