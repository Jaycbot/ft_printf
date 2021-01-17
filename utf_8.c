/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf_8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:25:50 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/18 00:49:19 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  utf_8_4B(wint_t unicode)
{
    unsigned char   unit;
    
    return (4);
}

static int  utf_8_3B(wint_t unicode)
{
    return (3);
}

static int  utf_8_2B(wint_t unicode)
{
    int ret;

    return (2);
}

static int utf_8_1B(wint_t unicode)
{
    unsigned char   unit;
    
    unit = 127 & unicode;
    write(1, &unit, 1);
    return (1);
}

int encode_utf_8(wint_t unicode)
{
    if (unicode | UTF_8_1B == UTF_8_1B)
        return (utf_8_1B(unicode));
    else if (unicode | UTF_8_2B == UTF_8_2B)
        return (utf_8_2B(unicode));
    else if (unicode | UTF_8_3B == UTF_8_3B)
        return (utf_8_3B(unicode));
    else if (unicode | UTF_8_4B == UTF_8_4B)
        return (utf_8_4B(unicode));
    return (-1);
}