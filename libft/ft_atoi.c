/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:29:38 by hwon              #+#    #+#             */
/*   Updated: 2021/05/10 18:40:08 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isoperator(int c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

int	isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					oper;

	num = 0;
	oper = 1;
	while (str && isspace(*str))
		str++;
	if (isoperator(*str))
		oper = isoperator(*str++);
	while (str && ft_isdigit(*str))
	{
		num *= 10;
		num += (*str - '0');
		str++;
	}
	if (num > LONG_MAX - 1 && oper == -1)
		return (0);
	if (num > LONG_MAX && oper == 1)
		return (-1);
	return ((int)(num * oper));
}
