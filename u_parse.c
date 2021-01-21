/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:15:06 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 01:04:05 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		itoa_free_u(unsigned long long n)
{
	char	*temp;

	temp = ft_itoa(n);
	ft_putstr(temp);
	free(temp);
}

void		itoa_nosign_free_u(unsigned long long n)
{
	char	*temp;

	temp = itoa_without_sign(n);
	ft_putstr(temp);
	free(temp);
}

int			cal_udigit(unsigned long long num)
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

int			parse_u(t_contents *contents, va_list ap)
{
	unsigned int		n;
	unsigned long		ln;
	unsigned long long	lln;

	modify_width(contents);
	if (contents->length == 0)
	{
		n = va_arg(ap, unsigned int);
		return (unint_parse(contents, n, cal_digit(n)));
	}
	else if (contents->length == 1)
	{
		ln = va_arg(ap, unsigned long);
		return (unint_parse(contents, ln, cal_digit(ln)));
	}
	else
	{
		lln = va_arg(ap, unsigned long long);
		return (unint_parse(contents, lln, cal_digit(lln)));
	}
}
