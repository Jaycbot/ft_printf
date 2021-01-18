/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:36:48 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/18 22:02:30 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int parse_spec(char type, t_contents *contents, va_list ap)
{
    int ret;
    
    if (type == 'c')
        ret = parse_c(contents, ap);
    else if (type == 's')
        ret = parse_s(contents, ap);
    else if (type == 'u')
        ret = parse_u(contents, ap);
    else if (type == 'd' || type == 'i')
        ret = parse_i(contents, ap);
    else if (type == 'x' || type == 'X')
        ret = parse_x(type, contents, ap);
    else if (type == 'p')
        ret = parse_p(contents, ap);
    else if (type == '%')
        ret = parse_perc(contents);
    return (ret);
}

void    check_flags(t_contents *contents, const char **format)
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

void    check_width(t_contents *contents, const char **format, va_list ap)
{
    
    if (ft_isdigit(**format))
    {
        contents->width = ft_atoi(*format);
        while (ft_isdigit(**format))
            ++(*format);
    }
    else if (**format == '*')
    {
        contents->width = va_arg(ap, int);
        ++(*format);
    }
}

void   check_pre(t_contents *contents, const char **format, va_list ap)
{
    if (**format == '.')
    {
        ++(*format);
        if (ft_isdigit(**format))
        {
            contents->precision = ft_atoi(*format);
            while (ft_isdigit(**format))
                ++(*format);
        }
        else if (**format == '*')
        {
            contents->precision = va_arg(ap, int);
            ++(*format);
        }
    }
}

int     ft_printf(const char *format, ...)
{
    int         ret;
    t_contents  contents;
    va_list     ap;

    va_start(ap, format);
    ret = 0;
    while (*format)
    {
        if (*format == '%')
        {
            content_init(&contents);
            check_flags(&contents, &format);
            check_width(&contents, &format, ap);
            check_pre(&contents, &format, ap);
            check_len(&contents, &format);
            if (ft_strchr(SPEC, *format))
               ret += parse_spec(*format++, &contents, ap);
        }
        else
            ret += ret_with_write(*format++);
    }
    return (ret);
}