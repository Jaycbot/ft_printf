/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 04:08:42 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/20 00:31:27 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_uni_s(wchar_t *uni, t_contents *f)
{
	int	n;
}

static int	plain_flag(char *str, int size, t_contents *f)
{
	int	n;
	
	n = (f->width < size) ? 0 : (f->width - size);
	if (f->minus)
	{
		print_substr(str, 0, size);
		while (n--)
			ret_with_write(' ');
	}
	else if (f->zero)
	{
		while (n--)
			ret_with_write('0');
		print_substr(str, 0, size);
	}
	else
	{
		while (n--)
			ret_with_write(' ');
		print_substr(str, 0, size);
	}
	return ((f->width > size ? f->sidth : size));
}

static int	parse_plain(char *str, t_contents *f)
{
	int	ret;
	int	len;
	int	print_size;

	ret = 0;
	len = ft_strlen(str);
	if (f->precision < 0)
		return (no_pre_plain(str, f));
	print_size = (f->precision > len ? len : f->precision);
	return (plain_flag(str , print_size, f));
}

int			parse_s(t_contents *contents, va_list ap)
{
	int		count;
	wchar_t	*uni_str;
	char	*str;

	if (f->width < 0)
	{
		f->minus = 1;
		f->width *= -1;
	}
	if (contents->length == 1)
	{
		uni_str = va_arg(ap, int *);
		if (!uni_str)
			uni_str = "(null)";
		count = parse_uni_s(uni_str, contents);
	}
	else
	{
		str = va_arg(ap, char *);
		if (!str)
			str = "(null)";
		count = parse_plain(str, contents);
	}
	return (count);
}
