/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:09:49 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/26 12:59:33 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_delimiter(char c, char d)
{
	if (c == d)
		return (1);
	return (0);
}

static size_t	word_counter(char *str, char d)
{
	size_t	nums;

	nums = 0;
	while (*str)
	{
		while (is_delimiter(*str, d))
			str++;
		if (*str == '\0')
			break ;
		while (!is_delimiter(*str, d) && *str)
			str++;
		++nums;
	}
	return (nums);
}

static char		*find_next(char *start, char c)
{
	char	*ret_p;
	char	*temp;
	size_t	word_start;
	size_t	size_word;

	temp = start;
	size_word = 0;
	while (!is_delimiter(*start, c) && *start)
	{
		++start;
		++size_word;
	}
	ret_p = (char *)malloc(sizeof(char) * (size_word + 1));
	word_start = 0;
	while (word_start < size_word)
		ret_p[word_start++] = *temp++;
	ret_p[word_start] = '\0';
	return (ret_p);
}

char			**ft_split(char const *s, char c)
{
	char	**ret_strs;
	char	*temp;
	size_t	n_words;
	size_t	i;

	if (!s)
		return (NULL);
	temp = (char *)s;
	n_words = word_counter(temp, c);
	if (!(ret_strs = (char **)malloc(sizeof(char *) * (n_words + 1))))
		return (NULL);
	i = 0;
	while (i < n_words)
	{
		while (is_delimiter(*temp, c) && *temp)
			++temp;
		ret_strs[i] = find_next(temp, c);
		while (!is_delimiter(*temp, c) && *temp)
			++temp;
		++i;
	}
	ret_strs[i] = NULL;
	return (ret_strs);
}
