/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:20:13 by hwon              #+#    #+#             */
/*   Updated: 2021/05/06 16:40:45 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	size_t		sub_start;
	size_t		start;
	char		*dup;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dup = malloc(s1_len + s2_len + 1);
	if (!dup)
		return (0);
	start = 0;
	sub_start = 0;
	while (s1[sub_start])
		dup[start++] = s1[sub_start++];
	sub_start = 0;
	while (s2[sub_start])
		dup[start++] = s2[sub_start++];
	dup[start] = 0;
	return (dup);
}
