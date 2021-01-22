/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:36:39 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 16:25:13 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_n(long long int n)
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

static size_t	size_un(unsigned long long n)
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

char			*ft_itoa_u(unsigned long long n)
{
	char	*ret;
	size_t	size;
	size_t	i;

	if (!n)
		return (ft_strdup("0"));
	size = size_un(n);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size] = 0;
	i = size - 1;
	while (n)
	{
		ret[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (i == 0)
		ret[i] = '-';
	return (ret);
}
