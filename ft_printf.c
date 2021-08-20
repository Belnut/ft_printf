/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:26:34 by hwon              #+#    #+#             */
/*   Updated: 2021/08/20 21:07:27 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	vprintf(t_format_info *info, va_list va)
{
	int	rst;
	int	type;

	rst = 0;
	if (!info || !va || info->type == 0)
		return (0);
	type = info->type;
	if (type == 'd' || type == 'i' || type == 'u'
		|| type == 'x' || type == 'X' || type == 'p')
		rst += ft_putnbr_info(info, va);
	else if (type == 'c')
		rst += ft_putchar_info(info, va);
	else if (type == 's')
		rst += ft_putstr_info(info, va);
	else if (type == '%')
		rst += write(1, &"%", 1);
	return (rst);
}

static int	format_parsing(const char *str, va_list va)
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
			info = ft_format_decode(++str);
			if (!info)
				break ;
			str += info->format_len;
			rst += vprintf(info, va);
			ft_delete_format_info(&info);
		}
		else
			rst += write(1, str++, 1);
	}
	return (rst);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = format_parsing(format, ap);
	va_end(ap);
	return (ret);
}
