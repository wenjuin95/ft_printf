/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:20:01 by welow             #+#    #+#             */
/*   Updated: 2023/10/31 12:47:03 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

char	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_puthexa_lower(unsigned long long nb);
int	ft_puthexa_upper(unsigned int nb);
int	ft_putaddress(unsigned long long ptr);
int	ft_printf(const char *format, ...);

#endif
