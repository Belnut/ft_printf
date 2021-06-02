/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <hwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:49:04 by hwon              #+#    #+#             */
/*   Updated: 2021/05/07 15:02:17 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*hook;

	if (lst == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	hook = *lst;
	while (hook->next != 0)
		hook = hook->next;
	hook->next = new;
}
