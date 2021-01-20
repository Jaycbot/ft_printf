/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 04:44:17 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/20 21:02:43 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pt_sep(int digit, t_contents *f, unsigned long pt)
{
	int	n;

	n = (f->width > digit) ? (f->width - digit) - 2 : digit - 2;
	if (n < 0)
		n = 0;
	if (f->minus)
	{
		pt_print(pt);
		while (n--)
			ret_with_write(' ');
	}
	else if (f->zero)
	{
		while (n--)
			ret_with_write('0');
		pt_print(pt);
	}
	else
	{
		while (n--)
			ret_with_write(' ');
		pt_print(pt);
	}
	return ((f->width > digit + 2) ? f->width : digit + 2);
}

int			parse_p(t_contents *contents, va_list ap)
{
	unsigned long	pt;
	int				digit;

	pt = va_arg(ap, unsigned long);
	digit = (!pt) ? 0 : 12;
	modify_width(contents);
	return (pt_sep(digit, contents, pt));
}
