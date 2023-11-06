/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:37:21 by welow             #+#    #+#             */
/*   Updated: 2023/11/06 21:39:33 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

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


/*flag*/
void	define_flags(t_flag *flags);
int		check_is_fs(char c);
void	handle_digit(char c, t_flag *flags);
int		check_flags(const char *str, int i, t_flag *flags);

/* ft_printf */
int		ft_printf(const char *format, ...);
int		printf_format(va_list list_argument, const char format, t_flag *flags);

/*print %c*/
char	ft_putchar(char c);
int		ft_putchar_minus(char c, t_flag *flags);
int		ft_putchar_flag(char c, t_flag *flags);

/*print %s*/
int		ft_putstr(char *str, int count);
int		ft_pustr_minus(char *str, int string_len, t_flag *flags);
int		ft_putstr_flag(char *str, t_flag *flags);

/*printf %i & %d*/


#endif