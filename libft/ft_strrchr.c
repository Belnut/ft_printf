/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <hwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:07:38 by hwon              #+#    #+#             */
/*   Updated: 2021/05/11 14:48:42 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*hook;

	hook = 0;
	while (*s)
	{
		if (*s == (char)c)
			hook = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (hook);
}
