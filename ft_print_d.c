/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:41:34 by hwon              #+#    #+#             */
/*   Updated: 2021/06/03 21:37:55 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define DIGIT_LEN 10

static int	get_count(t_format_info *info, int num)
{
	int				size;
	bool			sign;
	unsigned int	nbr;

	size = 0;
	if (num == 0) //add '+' option
		return (1);
	sign = false;
	nbr = (unsigned int)num;
	if (num < 0)
	{
		sign = true;
		nbr = (unsigned int)(-num);
	}
	while (nbr != 0)
	{
		num /= DIGIT_LEN;
		size++;
	}
	if (sign)
		size++;
	return (size);
}

static unsigned int	get_max_pwer_10(unsigned int nbr)
{
	unsigned int	power_10;

	power_10 = 10;
	while (nbr / power_10 >= 10)
		power_10 *= 10;
	return (power_10);
}

static void	write_num(t_format_info *info, int num)
{
	unsigned int	nbr;
	unsigned int	power_10;
	int				index;
	bool			sign;

	sign = false;
	index = 0;
	nbr = (unsigned int)num;
	if (num < 0)
	{
		nbr = (unsigned int)(-num);
		sign = true;
	}
	if (sign)
		info->mem[index++] = '-';
	power_10 = get_power_10(nbr);;
	while (power_10 != 1)
	{
		info->mem[index++] = "0123456789"[nbr / power_10];
		nbr %= power_10;
		power_10 /= 10;
	}
	info->mem[index] = "0123456789"[nbr];
}

static void	write_num_reverse(t_format_info *info, int num)
{
	unsigned int	nbr;
	int				index;
	bool			sign;

	sign = false;
	index = 0;
	nbr = (unsigned int)num;
	if (num < 0)
	{
		nbr = (unsigned int)(-num);
		sign = true;
	}
	if (sign)
		info->mem[index++] = '-';
	if (nbr == 0)
		info->mem[index] = '0';
	index = info->width - 1;
	while (nbr != 0)
	{
		info->mem[index--] = "0123456789"[nbr % 10];
		nbr %= 10;
	}	
}

int			ft_print_d(t_format_info *info, int num)
{
	int		size;

	size = get_count(num, false); //if you need to bonus! check + here	
	if (num < 0)
		size = get_count(-num, true);
	if (info->width < size)
		info->width = size;
	info->mem = malloc(info->width + 1);
	if (info->mem == 0)
		return (0);
	ft_memset(info->mem, info->width, info->filled);
	info->mem[info->width] = '\0';
	write_num(num, info);	
	ft_putstr(info->mem);
	return (info->width);
}
