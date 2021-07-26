/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:42:26 by hwon              #+#    #+#             */
/*   Updated: 2021/07/26 19:34:06 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_info(t_format_info *info, va_list *va)
{
	char	*str;

	if (info->type != 's')
		return (0);
	str = va_arg(*va, char *);
	return (write(1, str, ft_strlen(str)));
}
