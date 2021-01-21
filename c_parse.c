/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 04:03:22 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 02:29:27 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_unicode(wchar_t uni, t_contents *f, int iter, int size)
{
	if (f->minus)
	{
		encode_utf_8(uni);
		while (iter--)
			ret_with_write(' ');
	}
	else if (f->zero)
	{
		while (iter--)
			ret_with_write('0');
		encode_utf_8(uni);
	}
	else
	{
		while (iter--)
			ret_with_write(' ');
		encode_utf_8(uni);
	}
	return ((size < f->width) ? f->width : size);
}

static int	parse_uni_width(wchar_t uni, t_contents *f)
{
	int size;
	int i;

	size = uni_size(uni);
	i = f->width - size;
	if (i < size)
		i = 0;
	return (parse_unicode(uni, f, i, size));
}

static int	parse_width(t_contents *f, int c)
{
	int i;
	
	i = f->width - 1;
	if (i < 0)
		i = 0;
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
	return ((1 < f->width) ? f->width : 1);
}

int			parse_c(t_contents *contents, va_list ap)
{
	int				ret;
	wchar_t			unic;
	unsigned int	c;

	ret = 0;
	modify_width(contents);
	if (contents->length == 1)
	{
		unic = va_arg(ap, int);
		ret = parse_uni_width(unic, contents);
	}
	else
	{
		c = va_arg(ap, int);
		ret = parse_width(contents, c);
	}
	return (ret);
}
