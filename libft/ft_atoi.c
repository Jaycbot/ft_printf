/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:53:30 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/26 04:40:59 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\r' || c == '\v')
		return (1);
	if (c == '\f' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	long	ret;
	long	sign;
	char	*ascii;

	ascii = (char *)nptr;
	ret = 0;
	sign = 1;
	while (ft_isspace(*ascii))
		++ascii;
	if (*ascii == '+' || *ascii == '-')
	{
		sign = (*ascii == '-') ? -1 : 1;
		++ascii;
	}
	while (*ascii >= '0' && *ascii <= '9')
	{
		ret = (ret * 10) + (*ascii - '0') * sign;
		if (ret > 2147483647)
			return (-1);
		else if (ret < -2147483648)
			return (0);
		++ascii;
	}
	return (ret);
}
