/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_no_pre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:24:18 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 01:14:29 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	no_pre_plain(char *s, t_contents *f)
{
	int	len;
	int	n;

	len = ft_strlen(s);
	n = (f->width < len) ? 0 : (f->width - len);
	if (f->minus)
	{
		ft_putstr(s);
		while (n--)
			ret_with_write(' ');
	}
	else if (f->zero)
	{
		while (n--)
			ret_with_write('0');
		ft_putstr(s);
	}
	else
	{
		while (n--)
			ret_with_write(' ');
		ft_putstr(s);
	}
	return ((f->width < len) ? len : f->width);
}

int	no_pre_uni(wchar_t *uni, t_contents *f)
{
	int	len;
	int	n;

	len = uni_s_size(uni);
	n = (f->width < len) ? 0 : (f->width - len);
	if (f->minus)
	{
		ft_putuni(uni);
		while (n--)
			ret_with_write(' ');
	}
	else if (f->zero)
	{
		while (n--)
			ret_with_write('0');
		ft_putuni(uni);
	}
	else
	{
		while (n--)
			ret_with_write(' ');
		ft_putuni(uni);
	}
	return ((f->width < len) ? len : f->width);
}
