/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:06:35 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/24 21:11:33 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	char	*ret;
	int		index;

	ret = NULL;
	index = 0;
	while (str[index])
	{
		if (str[index] == (char)character)
			ret = (char *)&str[index];
		++index;
	}
	if ((char)character == 0)
		return ((char *)&str[index]);
	return (ret);
}
