/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:59:44 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/20 22:21:58 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modify_width(t_contents *f)
{
	if (f->width < 0)
	{
		f->minus = 1;
		f->width *= -1;
	}
}

void	fill_space(int num, char c)
{
	while (num--)
		ret_with_write(c);
}

char		*itoa_without_sign(long long int n)
{
	char	*ret;
	size_t	size;
	size_t	i;
	int		sign;

	if (!n)
		return (ft_strdup("0"));
	size = size_n(n);
	sign = (n < 0) ? -1 : 1;
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size] = 0;
	i = size - 1;
	while (n)
	{
		ret[i--] = (n % 10) * sign + '0';
		n /= 10;
	}
	return (ret);
}