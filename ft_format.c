/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:15:05 by hwon              #+#    #+#             */
/*   Updated: 2021/06/01 17:28:43 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format_info	*create_format_info()
{
	t_format_info	*info;
	
	info = malloc(sizeof(t_format_info));
	if (!info)
		return (0);	
	info->type = 0;
	info->width = 0;
	info->align = RIGHT;
	info->filled = ' ';
	return (info);
}

void			delete_format_info(t_format_info **info)
{
	if (*info == 0)
		return (0);
	free (*info);
	*info = 0;
}
