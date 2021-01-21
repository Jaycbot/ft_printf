/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:02:49 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 03:25:13 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_width(t_contents *f, int c)
{
	int i;

	i = (f->width > 1) ? f->width - 1 : 0;
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
	return ((f->width > 1) ? f->width : 1);
}

int			parse_perc(t_contents *contents)
{
	modify_width(contents);
	return (parse_width(contents, '%'));
}
