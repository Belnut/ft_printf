/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_decode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:19:32 by hwon              #+#    #+#             */
/*   Updated: 2021/06/01 22:18:51 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	istype(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c =='u')
		return (true);
	if (c == 'x' || c == 'X' || c == '%')
		return (true);
	return (false);
}

bool	check_type(int c, t_format_info *info)
{
	if (!info && !(*info))
		return (false);
	if (!istype(*str))
		return (false);
	info->type = *str;
	return (true);
}

char	*check_option(const char *str, t_format_info *info)
{
	int tmp;

	if (*str == '-')
		info->align = RIGHT;
	else if (*str == '0')
		info->filled = '0';
	else if (*str == '*')
		info->width = 0; //TODO: get arg value
	return (str++);
}

t_format_info	*ft_format_decode(const char *str)
{
	t_format_info *info;

	info = ft_create_format_info();
	if (!info || !str)
	{
		ft_delete_format_info(info);
		return (0);
	}
	while (*str)
	{
		if (check_type(*str, info))
			break;
		str = check_option(str, info);
	}
	return  (info);
}
