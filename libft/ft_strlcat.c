/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <hwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:45:50 by hwon              #+#    #+#             */
/*   Updated: 2021/05/06 21:34:05 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	len;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize < dstlen + 1)
		return (srclen + dstsize);
	len = dstsize - dstlen;
	len--;
	while (*dst)
		dst++;
	while (len-- != 0 && *src)
		*dst++ = *src++;
	*dst = 0;
	return (dstlen + srclen);
}
