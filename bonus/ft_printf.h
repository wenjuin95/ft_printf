/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:37:21 by welow             #+#    #+#             */
/*   Updated: 2023/10/27 21:00:12 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flag
{
	int		number;
	int		minus;
	int		zero;
	int		plus;
	int		dot;
	int		hash;
	int		space;
	int		width;
	int		precision;
	char	c;
}	t_flag;

/*flag*/
void	define_flags(t_flag *flags);
int		check_is_fs(char c);
int		input(char *format, int *i);
void	check_flags(char *str, int *i, t_flag *flags);

/* ft_printf */
int	ft_printf(const char *format, ...);

#endif