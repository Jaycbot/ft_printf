/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:33:03 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/24 21:09:29 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == (unsigned char)c)
			return ((char *)&str[index]);
		index++;
	}
	if (c == '\0')
		return ((char *)&str[index]);
	return (NULL);
}
