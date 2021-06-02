/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:50:43 by hwon              #+#    #+#             */
/*   Updated: 2021/06/03 00:04:37 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_count(unsigned int num, int digit, bool sign)
{
	size_t	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= digit;
		size++;
	}
	if (sign)
		size++;
	return (size);
}

static size_t	write_num(unsigned int num, const char *digit, int digit_len)
{
	size_t	size;

	size = 0;
	if (num >= digit_len)
		size += write_num(num / digit_len, digit, digit_len);
	size += write(1, &digit[num % digit_len], 1);
	return (size);
}

int				ft_putint(int num, int fill_char)
{
	int		size;

	size = get_count(num, 10, num < 0);
	return 0;
}
/*
int				ft_putuint(unsigned int num, int digit, const char *format)
{
	size_t	size;

	size = get_count(num, digit, num < 0);
}
*/
