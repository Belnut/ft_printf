/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <hwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:21:35 by hwon              #+#    #+#             */
/*   Updated: 2021/05/07 15:21:58 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*anchor;
	t_list	*tmp;

	anchor = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstdelone(tmp, del);
			ft_lstclear(&anchor, del);
			return (0);
		}
		tmp->next = 0;
		if (anchor == 0)
			anchor = tmp;
		else
			ft_lstadd_back(&anchor, tmp);
		lst = lst->next;
	}
	return (anchor);
}
