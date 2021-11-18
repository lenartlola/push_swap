/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:35:45 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/08 12:35:46 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print a character
int	ft_print_c(int c, t_options *option)
{
	int	ret;

	ret = 0;
	if (option->spec == '%' && option->negative == 1)
		option->zero = 0;
	if (option->negative == 1)
		ret += ft_putchar(c);
	ret += put_width_c(option->width, 1, option->zero);
	if (option->negative == 0)
		ret += ft_putchar(c);
	return (ret);
}

int	put_width_c(int width, int len, int zero)
{
	int	ret;

	ret = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		ret++;
	}
	return (ret);
}
