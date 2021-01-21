/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:29:29 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/26 02:07:22 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t index;

	index = 0;
	while (index < num)
	{
		if (str1[index] != str2[index] || !str1[index] || !str2[index])
			return ((unsigned char)str1[index] - (unsigned char)str2[index]);
		++index;
	}
	return (0);
}
