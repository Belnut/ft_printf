/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:57:20 by hwon              #+#    #+#             */
/*   Updated: 2021/05/07 16:21:24 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	size;

	if (!s || start < 0)
		return (0);
	size = len;
	if (ft_strlen(s) < start + len)
		size = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	dup = ft_strndup(&s[start], size);
	if (!dup)
		return (0);
	return (dup);
}
