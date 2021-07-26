/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:59:49 by hwon              #+#    #+#             */
/*   Updated: 2021/07/26 19:33:43 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_digit(int type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}

static long long	get_va_to_num(va_list *va, int type)
{
	if (type == 'p')
		return ((long long)va_arg(*va, unsigned long));
	else if (type == 'u')
		return ((long long)va_arg(*va, unsigned int));
	return ((long long)va_arg(*va, int));
}

static int	print_num(long long num, char *digit, t_format_info *info)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_num_to_str(num, digit, info->type);
	if (!str)
		return (0);
	if (num < 0 && (info->type == 'd' || info -> type == 'i'))
		len += write(1, "-", 1);
	if (info->type == 'p')
		len += write(1, "0x", 2);
	len += write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	ft_putnbr_info(t_format_info *info, va_list *va)
{
	char		*digit;
	long long	num;
	int			len;

	digit = get_digit(info->type);
	num = get_va_to_num(va, info->type);
	len = print_num(num, digit, info);
	return (len);
}
