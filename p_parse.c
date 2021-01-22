/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 04:44:17 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 17:00:33 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pt_sep(int digit, t_contents *f, unsigned long pt)
{
	int	n;

	n = (f->width > digit) ? (f->width - digit) - 2 : 0;
	if (n < 0)
		n = 0;
	if (f->minus)
	{
		pt_print(pt);
		fill_space(n, ' ');
	}
	else if (f->zero)
	{
		fill_space(n, '0');
		pt_print(pt);
	}
	else
	{
		fill_space(n, ' ');
		pt_print(pt);
	}
	return ((f->width > digit + 2) ? f->width : digit + 2);
}

int			parse_p(t_contents *contents, va_list ap)
{
	unsigned long	pt;
	int				digit;

	pt = va_arg(ap, unsigned long);
	digit = size_memory(pt);
	modify_width(contents);
	return (pt_sep(digit, contents, pt));
}
