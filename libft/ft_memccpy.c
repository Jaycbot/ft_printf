/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:02:08 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/26 01:40:22 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*j;
	unsigned char	*k;

	i = 0;
	j = (unsigned char *)dst;
	k = (unsigned char *)src;
	while (i < n)
	{
		if (k[i] == (unsigned char)c)
		{
			j[i] = k[i];
			++i;
			return (&j[i]);
		}
		j[i] = k[i];
		++i;
	}
	return (NULL);
}
