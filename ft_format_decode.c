/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_decode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:19:32 by hwon              #+#    #+#             */
/*   Updated: 2021/06/03 00:16:39 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*check_num_option(int opt_type, const char *str, t_format_info *info)
{
	if (opt_type == '.')
		info->prec = ft_atoi(str);
	if (opt_type == 'w')
		info->width = ft_atoi(str);
	while (*str && ft_isdigit(*(str + 1)))
		str++;
	return (char *)(str);
}

char	*check_option(const char *str, t_format_info *info, va_list *ap)
{
	int tmp;

	if (*str == '-')
		info->align = RIGHT;
	else if (*str == '0')
		info->filled = '0';
	else if (*str == '*')
		info->width = va_arg(*ap, int); 
	else if (*str == '.')
		str = check_num_option('.', str, info);	
	else if (ft_isdigit(*str))
		str = check_num_option('w', str, info);
	return (char *)(str++);
}

t_format_info	*ft_format_decode(const char *str, va_list *ap)
{
	t_format_info	*info;
	const char		*anchor;

	info = ft_create_format_info();
	anchor = str;
	if (!info || !str)
		return (ft_delete_format_info(&info));
	while (*str)
	{
		if (ft_isptype(*str) || check_type(*str++, info))
			break;
		str = (const char *)check_option(str, info, ap);
	}
	info->format_len = str - anchor;
	return  (info);
}

int				ft_format_parsing(const char *str, va_list ap)
{
	int				rst;
	t_format_info	*info;	

	rst = 0;
	if (!str)
		return (rst);
	while (*str)
	{
		if (*str == '%')
		{
			info = ft_format_decode(str, &ap);
			if (!info)
				break;
			str += info->format_len;
			rst += ft_vprintf(info, &ap);
			ft_delete_format_info(&info);
		}
		else
			rst += write(1, str++, 1);
	}
	return (rst);
}
