/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 23:47:46 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/18 23:12:17 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    content_init(t_contents *contents)
{
    contents->zero = 0;
    contents->minus = 0;
    contents->precision = DEFAULT;
    contents->width = 0;
    contents->length = 0;
}

void    check_len(t_contents *contents, const char **format)
{
    if (**format == 'l')
    {
        ++(*format);
        contents->length += 1;
        if (**format && **format == 'l')
        {
            contents->length += 1;
            ++(*format);
        }
    }
}

int	    ret_with_write(char c)
{
	return (write(1, &c, 1));
}
