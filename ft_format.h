/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:50:51 by hwon              #+#    #+#             */
/*   Updated: 2021/07/26 20:38:19 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_H
# define FT_FORMAT_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

enum	e_align
{
	RIGHT = 0,
	LEFT = 1
};

struct s_format_info
{
	char			type;
	int				width;
	enum e_align	align;
	int				filled;
	int				prec;
	int				format_len;
};
typedef struct s_format_info	t_format_info;

t_format_info	*ft_create_format_info(void);
void			ft_print_format_info(const t_format_info info);
t_format_info	*ft_delete_format_info(t_format_info **info);
bool			ft_isptype(int c);
bool			check_type(int c, t_format_info *info);
char			*check_num_option(int opt_t, const char *s, t_format_info *i);
char			*check_option(const char *str, t_format_info *info);
t_format_info	*ft_format_decode(const char *str);

#endif
