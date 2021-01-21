/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 23:47:46 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 02:54:44 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	content_init(t_contents *contents)
{
	contents->zero = 0;
	contents->minus = 0;
	contents->precision = DEFAULT;
	contents->width = 0;
	contents->length = 0;
	contents->cap = 0;
}

void	check_len(t_contents *contents, const char **format)
{
	if (**format == 'l')
	{
		++(*format);
		contents->length += 1;
		if (**format && **format == 'l')
		{
			contents->length += 1;
			++(*format);
		}
	}
}

int		ret_with_write(char c)
{
	return (write(1, &c, 1));
}

int		ft_putuni(wchar_t *uni)
{
	int read_b;

	read_b = 0;
	while (*uni)
		read_b += encode_utf_8(*uni++);
	return (read_b);
}

int		ft_putstr(char *c)
{
	int	read_b;

	read_b = 0;
	while (*c)
		read_b += write(1, c++, 1);
	return (read_b);
}
