/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:41:06 by jaehchoi          #+#    #+#             */
/*   Updated: 2021/01/22 21:05:44 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		uni_size(wchar_t uni)
{
	if ((uni | UTF_8_1B) == UTF_8_1B)
		return (1);
	else if ((uni | UTF_8_2B) == UTF_8_2B)
		return (2);
	else if ((uni | UTF_8_3B) == UTF_8_3B)
		return (3);
	else
		return (4);
}

int		uni_s_size(wchar_t *uni)
{
	int	size;

	size = 0;
	while (*uni)
	{
		size += uni_size(*uni);
		++uni;
	}
	return (size);
}

void	print_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;

	temp = ft_substr(s, start, len);
	if (!temp)
	{
		g_error = 1;
		return ;
	}
	ft_putstr(temp);
	free(temp);
}

int		uni_sub_size(wchar_t *uni, size_t len)
{
	size_t	count;
	size_t	temp;

	count = uni_size(*uni);
	if (len < count)
		return (0);
	while (count < len && *uni)
	{
		temp = uni_size(*uni);
		count += temp;
		++uni;
	}
	if (count != len)
		count -= temp;
	return (count);
}

void	print_uni_substr(wchar_t *uni, size_t len)
{
	size_t	count;

	count = uni_size(*uni);
	while (count < len)
	{
		count += encode_utf_8(*uni);
		++uni;
	}
}
