/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:19:33 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/20 21:42:30 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_neg_pre(t_contents *f, long long int n, int digit)
{
	int	i;
	int	minus;

	minus = (n < 0) ? 1 : 0;
	i = (f->width > digit + minus) ? f->width : (digit - minus);
	if (f->minus)
	{
		itoa_free(n);
		while (i--)
			ret_with_write(' ');
	}
	if (f->zero)
	{
		while (i--)
			ret_width_write('0');
		itoa_free(n);
	}
	else
	{
		while (i--)
			ret_width_write(' ');
		itoa_free(n);
	}
	return ((f->width > digit + minus) ? f->width : digit + minus);
}

int	int_parse(t_contents *f, int n, int digit)
{
	if (f->precision < 0)
		return (print_neg_pre(f, n, digit));
}
