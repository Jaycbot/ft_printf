/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_pt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:14:42 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 16:59:25 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			size_memory(unsigned long pt)
{
	int	size;

	size = 0;
	if (pt == 0)
		return (1);
	while (pt)
	{
		++size;
		pt /= 16;
	}
	return (size);
}

static void	print_mem(unsigned long pt, int depth, int destination)
{
	char *hex;

	hex = "0123456789abcdef";
	if (depth == destination)
		return ;
	print_mem(pt / 16, ++depth, destination);
	ret_with_write(hex[pt % 16]);
}

void		pt_print(unsigned long pt)
{
	ft_putstr("0x");
	if (pt == 0)
		ret_with_write('0');
	else
		print_mem(pt, 0, size_memory(pt));
}
