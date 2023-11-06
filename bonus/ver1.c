# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flag
{
	int		minus;
	int		zero;
	int		plus;
	int		dot;
	int		hash;
	int		space;
	int		width;
	int		precision;
}	t_flag;

/*utils*/
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (2048);
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

/*flags*/
void	define_flags(t_flag *flags)
{
	ft_bzero(flags, sizeof(t_flag));
}

int	check_is_fs(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i'
		|| c == 'p' || c == 'x' || c == 'X' || c == 'u'
		|| c == '%')
		return (1);
	return (0);
}

void	handle_digit(char c, t_flag *flags)
{
	if ('0' == c && !(flags->width) & !(flags->dot))
		flags->zero = 1;
	else if ('0' == c && flags->width && !(flags->dot))
		flags->width = (flags->width *= 10);
	else if ('0' == c && flags->dot)
		flags->precision = (flags->precision *= 10);
	else if (ft_isdigit((int)c))
	{
		if (!(flags->dot))
			flags->width = (flags->width * 10) + (c - 48);
		else if (flags->dot)
			flags->precision = (flags->precision * 10) + (c - 48);
	}
}

int	check_flags(const char *format, int i, t_flag *flags)
{
	char	is_flags;
	int		count;

	count = 0;
	while (!(check_is_fs(format[++i])))
	{
		is_flags = format[i];
		if (is_flags == '-')
			flags->minus = 1;
		else if (is_flags == '+')
			flags->plus = 1;
		else if (is_flags == '.')
			flags->dot = 1;
		else if (is_flags == '#')
			flags->hash = 1;
		else if (is_flags == ' ')
			flags->space = 1;
		else if (ft_isdigit(is_flags))
			handle_digit(is_flags, flags);
	}
	return (i);
}

/*putchar*/
char	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_minus(char c, t_flag *flags)
{
	int	count;

	count = 0;
	if (!(flags->minus))
	{
		while (flags->width > 1)
		{
			count += ft_putchar(' ');
			flags->width--;
		}
		count += (ft_putchar(c));
		return (count);
	}
	else
	{
		count += (ft_putchar(c));
		while (flags->width > 1)
		{
			count += ft_putchar(' ');
			flags->width--;
		}
		return (count);
	}
}

int	ft_putchar_flag(char c, t_flag *flags)
{
	int	count;

	count = 0;
	if (flags->width > 1)
		count += (ft_putchar_minus(c, flags));
	else
		count += (ft_putchar(c));
	return (count);
}

/*putstr*/
int	ft_putstr(char *str, int count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		count += (write(1, "(null)", 6));
		return (count);
	}
	else
	{
		while (str[i] && i < count)
		{
			i++;
		}
		count += (write(1, str, i));
		return (count);
	}	
}

int	ft_pustr_minus(char *str, int string_len, t_flag *flags)
{
	int	count;

	count = 0;
	if (!(flags->minus))
	{
		while (flags->width > string_len)
		{
			count += ft_putchar(' ');
			flags->width--;
		}
		count += (ft_putstr(str, (string_len - count)));
		return (count);
	}
	else
	{
		count += (ft_putstr(str, (string_len - count)));
		while (flags->width > string_len)
		{
			count += ft_putchar(' ');
			flags->width--;
		}
		return (count);
	}
}

int	ft_putstr_flag(char *str, t_flag *flags)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	if (flags->dot)
	{
		if (flags->width > flags->precision)
			count = (ft_pustr_minus(str, flags->precision, flags));
		else
			count += (ft_putstr(str, flags->precision));
	}
	else if (!(flags->dot))
	{
		if (flags->width > ft_strlen(str))
			count += (ft_pustr_minus(str, ft_strlen(str), flags));
		else
			count += (ft_putstr(str, ft_strlen(str)));
	}
	return (count);
}

/*printf*/
int	print_format(va_list list_arg, const char format, t_flag *flags)
{
	int		count;

	count = 0;
	if (format == 'c')
		count += ft_putchar_flag(va_arg(list_arg, int), flags);
	else if (format == 's')
		count += ft_putstr_flag(va_arg(list_arg, char *), flags);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		list_arg;
	int			i;
	int			count;
	t_flag		flags;

	i = 0;
	count = 0;
	va_start(list_arg, format);
	while (format[i])
	{
		define_flags(&flags);
		if (format[i] == '%')
		{
			i = check_flags(format, i, &flags);
			count += print_format(list_arg, format[i], &flags);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(list_arg);
	return (count);
}

#include <stdio.h>
int main()
{
	printf("%-9.2sm\n", "belo");
	ft_printf("%-9.2sm\n", "belo");
}