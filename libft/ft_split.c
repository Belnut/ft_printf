/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:55:24 by hwon              #+#    #+#             */
/*   Updated: 2021/05/11 13:16:50 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	const char	*start;
	int			word_size;
	int			count;

	count = 0;
	start = str;
	while (1)
	{
		while (*str != '\0' && *str == c)
			str++;
		start = str;
		word_size = 0;
		while (*str != '\0' && *str != c)
		{
			str++;
			word_size++;
		}
		if (word_size > 0)
			count++;
		if (*str == '\0')
			break ;
		str++;
	}
	return (count);
}

static int	add_words(char **dest, const char *str, char c)
{
	const char	*start;

	start = str;
	while (1)
	{
		while (*str != '\0' && *str == c)
			str++;
		start = str;
		while (*str != '\0' && *str != c)
			str++;
		if (str != start)
		{
			*dest = ft_strndup(start, str - start);
			if (dest == 0)
				return (0);
		}
		if (*str == '\0')
			break ;
		dest++;
	}
	return (1);
}

static void	free_mems(char **dest)
{
	char	**anchor;

	anchor = dest;
	while (*dest != 0)
		free(*dest++);
	free(anchor);
}

char		**ft_split(const char *str, char c)
{
	char	**words;
	int		size;

	if (!str)
		return (0);
	size = count_words(str, c);
	words = malloc(sizeof(char *) * (size + 1));
	if (words == 0)
		return (0);
	words = ft_memset(words, 0, (sizeof(char *) * (size + 1)));
	if (add_words(words, str, c) == 0)
	{
		free_mems(words);
		return (0);
	}
	words[size] = 0;
	return (words);
}
