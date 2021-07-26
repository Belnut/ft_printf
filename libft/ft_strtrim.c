/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:30:46 by hwon              #+#    #+#             */
/*   Updated: 2021/07/26 19:52:06 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_start(const char *str, const char *set)
{
	size_t	start;

	start = 0;
	while (str[start])
	{
		if (!ft_strchr(set, str[start]))
			break ;
		start++;
	}
	return (start);
}

int	find_back(const char *str, const char *set)
{
	size_t	back;

	if (ft_strlen(str) == 0)
		return (0);
	back = ft_strlen(str) - 1;
	while (back != 0)
	{
		if (!ft_strchr(set, str[back]))
			break ;
		back--;
	}
	return (back);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dup;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = find_start(s1, set);
	end = find_back(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	dup = ft_strndup(&s1[start], (end - start) + 1);
	return (dup);
}
