/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:51:45 by hwon              #+#    #+#             */
/*   Updated: 2021/05/11 13:08:27 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		digit_len(int n)
{
	int				len;
	unsigned int	num;

	if (n == 0)
		return (1);
	if (n < 0)
	{
		len = 1;
		num = n * -1;
	}
	else
	{
		len = 0;
		num = n;
	}
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*dup;
	int				len;
	unsigned int	num;

	len = digit_len(n);
	dup = malloc(len + 1);
	if (!dup)
		return (0);
	ft_memset(dup, 0, len + 1);
	num = n;
	if (n < 0)
	{
		num = n * -1;
		dup[0] = '-';
	}
	while (num != 0)
	{
		dup[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n == 0)
		dup[0] = '0';
	return (dup);
}
