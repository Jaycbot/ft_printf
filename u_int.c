/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:11:06 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 04:13:16 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_neg_pre_un(t_contents *f, unsigned long long n, int digit)
{
	int	i;

	i = (f->width > digit) ? f->width - digit : 0;
	if (f->minus)
	{
		itoa_free_u(n);
		while (i--)
			ret_with_write(' ');
	}
	else if (f->zero)
	{
		while (i--)
			ret_with_write('0');
		itoa_free_u(n);
	}
	else
	{
		while (i--)
			ret_with_write(' ');
		itoa_free_u(n);
	}
	return ((f->width > digit) ? f->width : digit);
}

static void	print_with_pad(t_contents *f, unsigned long long n, int d)
{
	int	i;

	i = f->precision - d;
	fill_space(i, '0');
	itoa_nosign_free_u(n);
}

static int	biggerpre(t_contents *f, unsigned long long n, int digit)
{
	int	i;

	i = (f->width > f->precision) ? f->width - f->precision : 0;
	if (f->minus)
	{
		print_with_pad(f, n, digit);
		fill_space(i, ' ');
	}
	else if (f->zero)
	{
		fill_space(i, '0');
		print_with_pad(f, n, digit);
	}
	else
	{
		fill_space(i, ' ');
		print_with_pad(f, n, digit);
	}
	return ((f->width > f->precision) ? f->width : f->precision);
}

int			print_pos_pre_un(t_contents *f, unsigned long long n, int digit)
{
	if (f->precision > digit)
		return (biggerpre(f, n, digit));
	else
		return (print_neg_pre_un(f, n, digit));
}

int			unint_parse(t_contents *f, unsigned long long n, int digit)
{
	if (f->precision <= 0)
	{
		if (f->precision == 0 && n == 0)
			--digit;
		return (print_neg_pre_un(f, n, digit));
	}
	return (print_pos_pre_un(f, n, digit));
}
