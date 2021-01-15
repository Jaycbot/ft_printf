/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 23:47:46 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/16 04:00:36 by jaehchoi         ###   ########.fr       */
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

int	ret_with_write(char c)
{
	write(1, &c, 1);
	return (1);
}