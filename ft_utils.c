/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 02:23:37 by hwon              #+#    #+#             */
/*   Updated: 2021/07/26 19:28:26 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_len(long long n, char *digit, int type)
{
	int			len;
	long long	digit_len;
	long long	num;		

	if (n == 0)
		return (1);
	if (n < 0 && (type == 'x' || type == 'X'))
		return (8);
	else if (n < 0 && (type == 'p'))
		return (16);
	len = 0;
	num = n;
	digit_len = ft_strlen(digit);
	if (n < 0)
		num = n * -1;
	while (num != 0)
	{
		len++;
		num /= digit_len;
	}
	return (len);
}

static unsigned long long	complement(long long n, int type)
{
	unsigned long long	num;

	if (n > 0)
		return ((unsigned long long)n);
	if (n < 0 && (type == 'd' || type == 'i'))
		return ((unsigned long long)n * -1);
	num = 0;
	if (type == 'x' || type == 'X')
		num = 0xffffffff;
	else if (type == 'p')
		num = 0xffffffffffffffff;
	num ^= (unsigned long long)n * -1;
	num += 1;
	return (num);
}	

char	*ft_num_to_str(long long n, char *digit, int type)
{
	char				*dup;
	int					len;
	unsigned long long	d_len;
	unsigned long long	num;

	len = digit_len(n, digit, type);
	dup = malloc(len + 1);
	if (!dup)
		return (0);
	d_len = (unsigned long long)ft_strlen(digit);
	ft_memset(dup, 0, len + 1);
	num = n;
	if (n < 0)
		num = complement(n, type);
	while (num != 0)
	{
		dup[--len] = digit[num % d_len];
		num /= d_len;
	}
	if (n == 0)
		dup[0] = '0';
	return (dup);
}
