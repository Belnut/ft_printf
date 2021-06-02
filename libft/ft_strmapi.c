/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:27:09 by hwon              #+#    #+#             */
/*   Updated: 2021/05/06 18:34:38 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	index;
	char	*dup;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (0);
	index = 0;
	while (s[index])
	{
		dup[index] = f(index, s[index]);
		index++;
	}
	dup[index] = 0;
	return (dup);
}
