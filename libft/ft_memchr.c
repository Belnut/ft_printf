/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <hwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:38:55 by hwon              #+#    #+#             */
/*   Updated: 2021/05/10 18:25:43 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*src;

	src = s;
	while (n-- != 0)
	{
		if (*src == (unsigned char)c)
			return ((void *)src);
		src++;
	}
	return (0);
}
