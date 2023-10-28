/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:37:21 by welow             #+#    #+#             */
/*   Updated: 2023/10/29 02:20:30 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

/*flag*/
void	define_flags(t_flag *flags);
int		check_is_fs(char c);
int		make_slot(const char *format, int i);
int		check_flags(char *str, int i, t_flag *flags);

/* ft_printf */
int		ft_printf(const char *format, ...);

#endif