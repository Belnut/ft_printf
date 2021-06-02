/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:46:45 by hwon              #+#    #+#             */
/*   Updated: 2021/05/07 01:35:26 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*anchor;

	dup = malloc(ft_strlen(s1) + 1);
	if (!dup)
		return (0);
	anchor = dup;
	while (*s1)
		*dup++ = *s1++;
	*dup = 0;
	return (anchor);
}
