/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 04:37:50 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 00:16:14 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_hex(unsigned long long hex, int depth, int digit, int capital)
{
	char *hex;

	if (capital)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (depth == digit)
		return ;
	print_hex(num / 16, ++depth);
	ret_with_write(hex[pt % 16]);
}

static void	cal_digit(unsigned long long n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		++digit;
		n /= 16;
	}
	return (digit);
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
		return (hex_parse(contents, n, cal_digit(n)));
	}
	else if (contents->length == 1)
	{
		ln = va_arg(ap, unsigned long);
		return (hex_parse(contents, ln, cal_digit(ln)));
	}
	else
	{
		lln = va_arg(ap, unsigned long long);
		return (hex_parse(contents, lln, cal_digit(lln)));
	}
}
