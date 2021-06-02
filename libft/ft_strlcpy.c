/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <hwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:32:23 by hwon              #+#    #+#             */
/*   Updated: 2021/05/07 01:37:30 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[index] && index < (dstsize - 1))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = 0;
	return (ft_strlen(src));
}
