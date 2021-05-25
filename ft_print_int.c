/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:50:43 by hwon              #+#    #+#             */
/*   Updated: 2021/05/25 23:21:46 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t	get_count(unsigned int num, int digit)
{
	size_t	size;
	bool	sign;

	size = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= digit;
		size++;
	}
	return (size);
}

static size_t	write_num(unsigned int num, const char *digit, int digit_len)
{
	size_t	size;

	size = 0;
	if (num >= digit_len)
		size += write_num(num / digit_len, digit, digit_len);
	size += write(1, digit[num % digit_len], 1);
	return (size);
}

int				ft_putint(int num, int digit, e_align align, int fill)
{
	int		size;

	size = 0;
	if (num < 0)
		size = 1;

}

int				ft_putuint(unsigned int num, int digit, e_align align, int fill)
{
}
