/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:37:47 by hwon              #+#    #+#             */
/*   Updated: 2021/05/10 18:48:38 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;
	char	*anchor;

	dup = malloc(sizeof(char) * (n + 1));
	if (dup == 0)
		return (0);
	anchor = dup;
	while (n > 0)
	{
		*dup++ = *str++;
		n--;
	}
	*dup = '\0';
	return (anchor);
}
