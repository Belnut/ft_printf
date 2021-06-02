/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:26:34 by hwon              #+#    #+#             */
/*   Updated: 2021/06/02 23:52:41 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vprintf(t_format_info *info, va_list *va)
{
	int	rst;
	int type;

	if (!info || !va || info->type == 0)
		return (0);
	type = info->type;
	if (type == 'd' || type == 'i' || type == 'u' 
			|| type == 'x' || type == 'X')
		rst += ft_putnbr_info(info, va_arg(*va, int));
	else if (type == 'c')
		rst += ft_putchar_info(info, va_arg(*va, int));
	else if (type == 's')
		rst += ft_putstr_info(info, va_arg(*va, char *));
	else if (type == '%')
		rst += ft_putchar_info(info, '%');
	else if (type == 'p')
		rst += ft_putaddr_info(info, va_arg(*va, void *)); 
	return (rst);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_format_parsing(format, ap);
	va_end(ap);
	return (ret);
}
