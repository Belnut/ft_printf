/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:15:05 by hwon              #+#    #+#             */
/*   Updated: 2021/08/20 23:08:44 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"

t_format_info	*ft_create_format_info(void)
{
	t_format_info	*info;

	info = malloc(sizeof(t_format_info));
	if (!info)
		return (0);
	info->type = 0;
	info->format_len = 0;
	return (info);
}

t_format_info	*ft_delete_format_info(t_format_info **info)
{
	if (*info == 0)
		return (0);
	free (*info);
	*info = 0;
	return (0);
}
