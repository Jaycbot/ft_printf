/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_pt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:14:42 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/20 16:19:01 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_mem(unsigned long pt, int depth)
{
	char *hex = "0123456789abcdef";
	
	if (depth == 12)
		return ;
	print_mem(pt / 16, ++depth);
	ret_with_write(hex[pt % 16]);
}

void		pt_print(unsigned long pt)
{
	ft_putstr("0x");
	if (pt == 0)
		ret_with_write('0');
	else
		print_mem(pt, 0);
}
