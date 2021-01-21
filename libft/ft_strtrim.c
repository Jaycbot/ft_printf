/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:15:19 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/26 15:06:23 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_set(char c, char const *set)
{
	int	cursor;

	cursor = 0;
	while (set[cursor])
	{
		if (set[cursor] == c)
			return (1);
		++cursor;
	}
	return (0);
}

static size_t	find_end(char const *s1, char const *set, size_t len)
{
	size_t	ret;

	ret = 0;
	while (ret < len && is_in_set(s1[len - ret - 1], set))
		ret++;
	return (len - ret);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		++start;
	end = find_end(s1, set, ft_strlen(s1));
	if (start >= end)
		return (ft_strdup(""));
	if (!(trimmed = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	ft_strlcpy(trimmed, &s1[start], end - start + 1);
	return (trimmed);
}
