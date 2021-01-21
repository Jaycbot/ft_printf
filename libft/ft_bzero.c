/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 02:33:49 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/22 02:40:53 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	size_t	i;
	char	*cur;

	if (size == 0)
		return ;
	i = 0;
	cur = ptr;
	while (i < size)
		cur[i++] = 0;
}
