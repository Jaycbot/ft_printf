/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 04:37:50 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 01:12:15 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_hex(unsigned long long num, int depth, int digit, int capital)
{
	char *hex;

	if (capital)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (depth == digit)
		return ;
	print_hex(num / 16, ++depth, digit, capital);
	ret_with_write(hex[num % 16]);
}

int			parse_x(char type, t_contents *contents, va_list ap)
{
	unsigned int		n;
	unsigned long		ln;
	unsigned long long	lln;

	modify_width(contents);
	if (type == 'X')
		contents->cap = 1;
	if (contents->length == 0)
	{
		n = va_arg(ap, unsigned int);
		return (hex_parse(contents, n, cal_udigit(n)));
	}
	else if (contents->length == 1)
	{
		ln = va_arg(ap, unsigned long);
		return (hex_parse(contents, ln, cal_udigit(ln)));
	}
	else
	{
		lln = va_arg(ap, unsigned long long);
		return (hex_parse(contents, lln, cal_udigit(lln)));
	}
}
