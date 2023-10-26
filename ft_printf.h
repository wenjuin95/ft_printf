/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:20:01 by welow             #+#    #+#             */
/*   Updated: 2023/10/26 21:44:05 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar(char c);
int	ft_putnbr_base(long n, int base);
int	ft_putstr(char *str);
int	ft_puthexa_base(long n, int base);
int	ft_putaddress(unsigned long long n, int base);
int	ft_printf(const char *str, ...);

#endif