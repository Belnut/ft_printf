/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:41:52 by hwon              #+#    #+#             */
/*   Updated: 2021/05/07 01:34:48 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dup;

	if (count < 0 || size < 0)
		return (0);
	dup = malloc(count * size);
	if (!dup)
		return (0);
	dup = ft_memset(dup, 0, count * size);
	return (dup);
}
