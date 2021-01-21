/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:13:13 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/24 21:21:06 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	k = 0;
	while (k < i)
	{
		ret[k] = s1[k];
		++k;
	}
	l = 0;
	while (k < i + j)
		ret[k++] = s2[l++];
	ret[k] = 0;
	return (ret);
}
