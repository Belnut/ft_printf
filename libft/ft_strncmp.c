/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <hwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:14:24 by hwon              #+#    #+#             */
/*   Updated: 2021/05/10 18:36:53 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cmp_char(char c1, char c2)
{
	return ((unsigned char)c1 - (unsigned char)c2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		cmp;

	cmp = 0;
	while (*s1 && *s2 && n)
	{
		cmp = cmp_char(*s1++, *s2++);
		if (cmp != 0)
			return (cmp);
		n--;
	}
	if (n != 0)
		return (cmp_char(*s1, *s2));
	return (cmp);
}
