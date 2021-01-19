/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:29:37 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/26 15:40:35 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	idx_cat;

	idx_cat = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	if (size < dst_len + 1)
		return (size + src_len);
	while ((dst_len + idx_cat < size - 1) && src[idx_cat])
	{
		dst[dst_len + idx_cat] = src[idx_cat];
		++idx_cat;
	}
	dst[dst_len + idx_cat] = 0;
	return (src_len + dst_len);
}
