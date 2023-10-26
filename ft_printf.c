/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:15:50 by welow             #+#    #+#             */
/*   Updated: 2023/10/26 21:44:43 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <unistd.h>
// #include <stdarg.h>
// #include <stdlib.h>

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putstr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	write(1, str, i);
// }

// void	ft_putnbr(int n)
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
// }

// void	ft_putunsigned(unsigned int n)
// {

// 	if (n >= 10)
// 	{
// 		ft_putunsigned(n / 10);
// 		ft_putchar(n % 10 + '0');
// 	}
// 	else
// 		ft_putchar(n + '0');
// }

// void	ft_pointer(size_t pointer)
// {
// 	char	*str;
// 	int		i;
// 	char	*base;

// 	str = malloc(18 * sizeof(char));
// 	if (str == NULL)
// 		return ;
// 	base = "0123456789abcdef";
// 	i = 0;
// 	write(1, "0x", 2);
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

// void	ft_puthexa(size_t pointer, char format)
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

int	printf_format(va_list list_argument, const char str)
{
	int		count;
	void	*ptr;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(list_argument, int));
	else if (str == 's')
		count += ft_putstr(va_arg(list_argument, char *));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr_base(va_arg(list_argument, int), 10);
	else if (str == 'x')
		count += ft_putnbr_base(va_arg(list_argument, unsigned int), 16);
	else if (str == 'X')
		count += ft_puthexa_base(va_arg(list_argument, unsigned int), 16);
	else if (str == 'u')
		count += ft_putnbr_base(va_arg(list_argument, unsigned int), 10);
	else if (str == 'p')
	{
		ptr = va_arg(list_argument, void *);
		count += ft_putstr("0x");
		count += ft_putaddress((unsigned long long)ptr, 16);
	}
	else if (str == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		list_argument;
	int			i;
	int			char_print;

	i = 0;
	char_print = 0;
	if (format == NULL)
		return (-1);
	va_start(list_argument, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_print += printf_format(list_argument, format[i + 1]);
			i++;
		}
		else
			char_print += ft_putchar(format[i]);
		i++;
	}
	va_end(list_argument);
	return (char_print);
}

