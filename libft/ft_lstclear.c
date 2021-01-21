/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehchoi <jaehchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:14:15 by jaehchoi          #+#    #+#             */
/*   Updated: 2020/12/26 02:13:00 by jaehchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*to_del;

	if (!del || !lst)
		return ;
	temp = *lst;
	while (temp)
	{
		to_del = temp;
		temp = temp->next;
		del(to_del->content);
		free(to_del);
	}
	*lst = NULL;
}
