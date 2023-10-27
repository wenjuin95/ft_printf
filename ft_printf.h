/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:20:01 by welow             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/27 14:06:37 by welow            ###   ########.fr       */
=======
/*   Updated: 2023/10/27 00:51:58 by welow            ###   ########.fr       */
>>>>>>> bd2747d10ee513f69bc9a8d96520769c53b94c18
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
<<<<<<< HEAD
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_puthexa_lower(unsigned int nb);
int	ft_puthexa_upper(unsigned int nb);
int	ft_putaddress(unsigned long long ptr);
int	ft_printf(const char *format, ...);
=======
int	ft_puthexa_base(long n, int base, int is_upper);
int	ft_putaddress(unsigned long long n, int base);
int	ft_printf(const char *str, ...);
>>>>>>> bd2747d10ee513f69bc9a8d96520769c53b94c18

#endif