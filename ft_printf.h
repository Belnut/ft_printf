/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:10:30 by hwon              #+#    #+#             */
/*   Updated: 2021/08/20 21:15:00 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include "ft_format.h"

int		ft_putnbr_info(t_format_info *info, va_list va);
int		ft_putchar_info(t_format_info *info, va_list va);
int		ft_putstr_info(t_format_info *info, va_list va);
int		ft_printf(const char *str, ...);
char	*ft_num_to_str(long long n, char *digit, int type);
#endif
