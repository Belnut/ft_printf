/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <hwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:04:10 by hwon              #+#    #+#             */
/*   Updated: 2021/05/10 18:24:29 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dst;
	s = (unsigned char *)src;
	while (n-- != 0)
	{
		*d++ = *s++;
		if (*(s - 1) == (unsigned char)c)
			return ((void *)(d));
	}
	return (0);
}
