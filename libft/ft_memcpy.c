/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 03:01:23 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/26 01:48:05 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	size_t			i;
	unsigned char	*j;
	unsigned char	*k;

	if (!dst && !src)
		return (NULL);
	i = 0;
	j = (unsigned char *)dst;
	k = (unsigned char *)src;
	while (i < num)
	{
		j[i] = k[i];
		++i;
	}
	return (dst);
}
