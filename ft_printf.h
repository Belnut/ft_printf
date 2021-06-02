/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:10:30 by hwon              #+#    #+#             */
/*   Updated: 2021/06/03 00:13:35 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

enum e_align {
	RIGHT = 0,
	LEFT = 1
};

typedef struct {
	char			type;
	int				width;
	enum e_align	align;
	int				filled;
	int				prec;
	int				format_len;
} t_format_info;

t_format_info	*ft_create_format_info();
t_format_info	*ft_delete_format_info(t_format_info **info);
bool			ft_isptype(int c);
bool			check_type(int c, t_format_info *info);
char			*check_num_option(int opt_t, const char *s, t_format_info *i);
char			*check_option(const char *str, t_format_info *info, va_list *ap);
t_format_info	*ft_format_decode(const char *str, va_list *ap);
int				ft_format_parsing(const char *str, va_list ap);
int				ft_putnbr_info(t_format_info *info, int num);
int				ft_putchar_info(t_format_info *info, int c);
int				ft_putstr_info(t_format_info *info, char *str);
int				ft_putaddr_info(t_format_info *info, void *addr);
int				ft_vprintf(t_format_info *info, va_list *va);
int				ft_printf(const char *str, ...);
#endif
