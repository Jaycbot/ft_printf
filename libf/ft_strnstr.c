/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:55:32 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/26 03:37:41 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!(*little))
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		k = 0;
		if (big[i] == little[k])
		{
			j = i;
			while (big[j] == little[k] && little[k] && j < len && k < len)
			{
				++j;
				++k;
			}
			if (!(little[k]))
				return ((char *)&big[i]);
		}
		++i;
	}
	return (NULL);
}
