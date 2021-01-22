/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 04:33:27 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 13:46:38 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		itoa_free(long long int n)
{
	char	*temp;

	temp = ft_itoa(n);
	ft_putstr(temp);
	free(temp);
}

void		itoa_nosign_free(long long int n)
{
	char	*temp;

	temp = itoa_without_sign(n);
	ft_putstr(temp);
	free(temp);
}

int			cal_digit(long long int num)
{
	int	digit;

	digit = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		++digit;
		num /= 10;
	}
	return (digit);
}

void		print_minus(int is_m)
{
	if (is_m)
		ret_with_write('-');
}

int			parse_i(t_contents *contents, va_list ap)
{
	int				n;
	long int		ln;
	long long int	lln;

	modify_width(contents);
	if (contents->length == 0)
	{
		n = va_arg(ap, int);
		return (int_parse(contents, n, cal_digit(n)));
	}
	else if (contents->length == 1)
	{
		ln = va_arg(ap, long int);
		return (int_parse(contents, ln, cal_digit(ln)));
	}
	else
	{
		lln = va_arg(ap, long long int);
		return (int_parse(contents, lln, cal_digit(lln)));
	}
}
