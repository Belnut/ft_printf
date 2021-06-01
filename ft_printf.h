/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:10:30 by hwon              #+#    #+#             */
/*   Updated: 2021/06/01 17:24:01 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

enum e_align {
	RIGHT = 0,
	LEFT = 1
};

typedef struct {
	char	type;
	int		width;
	e_align	align;
	int		filled;
} t_format_info;

#endif
