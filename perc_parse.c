/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:02:49 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/19 01:07:56 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_width(t_contents *f, int c)
{
	int i;

	f->width = (f->width < 0) ? -f->width : f->width;
	i = f->width - 1;
	if (f->minus)
	{
		ret_with_write(c);
		while (i--)
			ret_with_write(' ');
	}
	else if (f->zero)
	{
		while (i--)
			ret_with_write('0');
		ret_with_write(c);
	}
	else
	{
		while (i--)
			ret_with_write(' ');
		ret_with_write(c);
	}
	return ((1 < f->width) ? 1 : f->width);
}

int			parse_perc(t_contents *contents)
{
	if (contents->width < 0)
		contents->minus = 1;
	return (parse_width(contents, '%'));
}
