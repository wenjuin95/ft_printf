/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:41:11 by welow             #+#    #+#             */
/*   Updated: 2023/10/29 00:59:59 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_printf(const char *format, ...)
{
    va_list		args;
    t_flag		flags;
    int			i;
    int			len;

    i = 0;
    len = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            define_flags(&flags);
            check_flags((char *)format, &i, &flags);
            len += check_fs((char *)format, &i, &flags, args);
        }
        else
        {
            ft_putchar(format[i]);
            len++;
        }
        i++;
    }
    va_end(args);
    return (len);
}
