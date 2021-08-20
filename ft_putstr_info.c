/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:42:26 by hwon              #+#    #+#             */
/*   Updated: 2021/08/20 21:16:40 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_info(t_format_info *info, va_list va)
{
	char	*str;

	if (info->type != 's')
		return (0);
	str = va_arg(va, char *);
	if (str == 0)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}
