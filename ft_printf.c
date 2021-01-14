/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:36:48 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/15 02:18:20 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    content_init(t_contents *contents)
{
    contents->zero = 0;
    contents->minus = 0;
    contents->precision = DEFAULT;
    contents->width = 0;
}

void check_flags(t_contents *contents, va_list ap, const char **format)
{
    if (**format == '-')
    {
        ++(*format);
        while (**format == '-' || **format == '0')
            ++(*format);
        contents->minus = 1;
    }
    else if (**format == '0')
    {
        ++(*format);
        contents->zero = 1;
        while (**format == '0' || **format == '-')
        {
            if (**format == '-')
                contents->minus = 1;
            ++(*format);
        }
        if (contents->minus)
            contents->zero = 0;
    }
}

int ft_printf(const char *format, ...)
{
    int         ret;
    int         i;
    t_contents  contents;
    va_list     ap;

    va_start(ap, format);
    ret = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            content_init(&contents);
            check_flags(&contents, ap, &format);
            //while (format[++i] && !ft_strchr("cspdiuxX%", format[i]))            
            //    add_contents(&contents, ap, format[i]);
        }
        else
            write(1, &format[i++], 1);
    }
    return (ret);
}