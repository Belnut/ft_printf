/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <hwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:58:04 by hwon              #+#    #+#             */
/*   Updated: 2021/05/07 15:14:21 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == 0)
		return ;
	if (*lst == 0)
	{
		free(lst);
		lst = 0;
		return ;
	}
	while (*lst != 0)
	{
		del((*lst)->content);
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	lst = 0;
	return ;
}
