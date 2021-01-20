/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:36:39 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/20 21:13:32 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_n(int n)
{
	size_t	ret;

	ret = 0;
	while (n)
	{
		++ret;
		n /= 10;
	}
	return (ret);
}

char			*ft_itoa(long long int n)
{
	char	*ret;
	size_t	size;
	size_t	i;
	int		sign;

	if (!n)
		return (ft_strdup("0"));
	size = size_n(n);
	sign = (n < 0) ? -1 : 1;
	if (sign == -1)
		++size;
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size] = 0;
	i = size - 1;
	while (n)
	{
		ret[i--] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (i == 0)
		ret[i] = '-';
	return (ret);
}
