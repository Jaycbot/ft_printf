/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf_8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:25:50 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/19 22:39:08 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  utf_8_4B(wchar_t unicode)
{
    unsigned char   unit;

    unit = (unicode >> 18 & 0x7) | 0xf0;
    write(1, &unit, 1);
    unit = (unicode >> 12 & 0x3f) | 0x80;
    write(1, &unit, 1);
    unit = (unicode >> 6 & 0x3f) | 0x80;
    write(1, &unit, 1);
    unit = (unicode & 0x3f) | 0x80;
    write (1, &unit, 1);
    return (4);
}

static int  utf_8_3B(wchar_t unicode)
{
    unsigned char   unit;

    unit = (unicode >> 12 & 0xf) | 0xe0;
    write(1, &unit, 1);
    unit = (unicode >> 6 & 0x3f) | 0x80;
    write(1, &unit, 1);
    unit = (unicode & 0x3f) | 0x80;
    write (1, &unit, 1);
    return (3);
}

static int  utf_8_2B(wchar_t unicode)
{
    unsigned char   unit;

    unit = (unicode >> 6) | 0xc0;
    write(1, &unit, 1);
    unit = (unicode & 0x3f) | 0x80;
    write(1, &unit, 1);
    return (2);
}

static int utf_8_1B(wchar_t unicode)
{
    unsigned char   unit;
    
    unit = 0x7f & unicode;
    write(1, &unit, 1);
    return (1);
}

int encode_utf_8(wchar_t unicode)
{
    if ((unicode | UTF_8_1B) == UTF_8_1B)
        return (utf_8_1B(unicode));
    else if ((unicode | UTF_8_2B) == UTF_8_2B)
        return (utf_8_2B(unicode));
    else if ((unicode | UTF_8_3B) == UTF_8_3B)
        return (utf_8_3B(unicode));
    else if ((unicode | UTF_8_4B) == UTF_8_4B)
        return (utf_8_4B(unicode));
    return (-1);
}
