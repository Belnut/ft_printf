/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_decode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:19:32 by hwon              #+#    #+#             */
/*   Updated: 2021/05/31 23:37:44 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format_info	*ft_format_decode(const char *str)
{
	t_format_info *info;

	info = ft_create_info();
	if (!info)
		return (0);
	while (!*str)
	{
		if (ft_istype(*str))
		{
			check_type(str, info);
			break;
		}
		str = check_optino(str, info);
	}
	return  (info);
}	
