/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:19:33 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 04:13:03 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_neg_pre_n(t_contents *f, long long int n, int digit)
{
	int	i;
	int	minus;

	minus = (n < 0) ? 1 : 0;
	i = (f->width >= (digit + minus)) ? (f->width - digit) - minus : 0;
	if (f->minus)
	{
		itoa_free(n);
		while (i--)
			ret_with_write(' ');
	}
	else if (f->zero)
	{
		while (i--)
			ret_with_write('0');
		itoa_free(n);
	}
	else
	{
		while (i--)
			ret_with_write(' ');
		itoa_free(n);
	}
	return ((f->width > digit + minus) ? f->width : digit + minus);
}

static void	print_with_pad(t_contents *f, long long int n, int d, int m)
{
	int	i;

	i = f->precision - d;
	if (m == 1)
		ret_with_write('-');
	fill_space(i, '0');
	itoa_nosign_free(n);
}

static int	biggerpre(t_contents *f, long long int n, int digit, int m)
{
	int	i;

	i = (f->width > f->precision + m) ? f->width - f->precision - m : 0;
	if (f->minus)
	{
		print_with_pad(f, n, digit, m);
		fill_space(i, ' ');
	}
	else if (f->zero)
	{
		fill_space(i, '0');
		print_with_pad(f, n, digit, m);
	}
	else
	{
		fill_space(i, ' ');
		print_with_pad(f, n, digit, m);
	}
	return ((f->width > f->precision + m) ? f->width : f->precision + m);
}

int			print_pos_pre_n(t_contents *f, long long int n, int digit)
{
	int	minus;

	minus = (n < 0) ? 1 : 0;
	if (f->precision > digit)
		return (biggerpre(f, n, digit, minus));
	else
		return (print_neg_pre_n(f, n, digit));
}

int			int_parse(t_contents *f, long long int n, int digit)
{
	if (f->precision <= 0)
	{
		if (f->precision == 0 && n == 0)
			--digit;
		return (print_neg_pre_n(f, n, digit));
	}
	return (print_pos_pre_n(f, n, digit));
}
