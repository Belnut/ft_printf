/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_decode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:19:32 by hwon              #+#    #+#             */
/*   Updated: 2021/07/26 19:24:23 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"

bool	ft_isptype(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c =='u')
		return (true);
	if (c == 'x' || c == 'X' || c == '%')
		return (true);
	return (false);
}

bool	check_type(int c, t_format_info *info)
{
	info->type = c;
	return (true);
}

t_format_info	*ft_format_decode(const char *str)
{
	t_format_info	*info;
	const char		*anchor;

	info = ft_create_format_info();
	anchor = str;
	if (!info || !str)
		return (ft_delete_format_info(&info));
	while (*str)
	{
		if (ft_isptype(*str))
		{
			info->type = *str++;
			break ;
		}
		str++;
	}
	info->format_len = str - anchor;
	return (info);
}
