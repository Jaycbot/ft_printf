/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:00:46 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/26 03:11:47 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (len == 0 || (dst == 0 && src == 0))
		return (dst);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			++i;
		}
	}
	else
	{
		i = len;
		while (i)
		{
			*(unsigned char *)(dst + i - 1) = *(unsigned char *)(src + i - 1);
			--i;
		}
	}
	return (dst);
}
