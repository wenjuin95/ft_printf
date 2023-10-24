/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:15:50 by welow             #+#    #+#             */
/*   Updated: 2023/10/24 21:52:21 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <unistd.h>
// #include <stdarg.h>

// int	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

// int	ft_putstr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	write(1, str, i);
// 	return (i);
// }

// int	ft_putnbr(int n)
// {
// 	long	nb;

// 	nb = n;
// 	if (nb < 0)
// 	{
// 		ft_putchar('-');
// 		nb *= -1;
// 	}
// 	if (nb >= 10)
// 	{
// 		ft_putnbr(nb / 10);
// 		ft_putchar(nb % 10 + '0');
// 	}
// 	else
// 		ft_putchar(nb + '0');
// 	return (nb);
// }

// int	ft_putunsigned(unsigned int n)
// {

// 	if (n >= 10)
// 	{
// 		ft_putunsigned(n / 10);
// 		ft_putchar(n % 10 + '0');
// 	}
// 	else
// 		ft_putchar(n + '0');
// 	return (n);
// }

int	printf_format(char str, va_list ap)
{

	if (str == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(ap, char *)));
	// else if (str = 'p')
	// 	count += /*code*/
	else if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (str == 'u')
		return (ft_putunsigned(va_arg(ap, unsigned int)));
	// else if (str == 'x' || str == 'X')
	// 	count += /*code*/
	else if (str == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			count += printf_format(*(str + 1), ap);
			str++;
		}
		else
			count += ft_putchar(*(str));
		str++;
	}
	va_end(ap);
	return (count);
}

#include <stdio.h>

int main()
{
	// ft_printf("%s\n", "sda");
	// ft_printf("%c\n", 's');
	// ft_printf("%i\n", 999999999);
	// ft_printf("%%\n");
	ft_printf("%u\n", 99999999);
}
