/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:42:05 by hwon              #+#    #+#             */
/*   Updated: 2021/07/26 19:27:24 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_info(t_format_info *info, va_list *va)
{
	char	c;

	if (info->type != 'c')
		return (0);
	c = va_arg(*va, int);
	return (write(1, &c, 1));
}
