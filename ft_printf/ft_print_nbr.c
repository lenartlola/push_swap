/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:50:01 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/09 10:31:05 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_prefix(char **buffer)
{
	*buffer = ft_strjoin("0x", *buffer, 2);
	return (ft_strlen(*buffer));
}

int	ft_put_minus(t_options *option, char **buffer)
{
	int	l;

	l = 0;
	if ((option->spec == 'i' || option->spec == 'd' )
		&& option->zero == 0 && option->sign == -1)
	{
		*buffer = ft_strjoin("-", *buffer, 2);
		l = 1;
	}
	return (l);
}

int	ft_put_minus1(int buffer_len, t_options *option, char **buffer)
{
	int	l;

	l = 0;
	if (option->sign == -1 && option->zero == 1)
	{
		if (buffer_len >= option->width)
		{
			*buffer = ft_strjoin("-", *buffer, 2);
			l = 1;
		}
		else if (buffer_len < option->width)
			*buffer[0] = '-';
	}
	return (l);
}

int	ft_put_precision(unsigned long long nbr, t_options *option, char **buffer)
{
	int	buffer_len;
	int	ret;
	int	i;

	buffer_len = ft_nbrlen(nbr, option);
	if (option->precision > buffer_len)
		ret = option->precision;
	else
		ret = buffer_len;
	*buffer = (char *)malloc(sizeof(char) * ret + 1);
	if (!(*buffer))
		return (0);
	i = -1;
	(*buffer)[ret] = '\0';
	while (buffer_len + ++i < ret)
		(*buffer)[i] = '0';
	i = 1;
	if (nbr == 0 && option->precision != 0)
		(*buffer)[ret - i] = '0';
	while (nbr)
	{
		(*buffer)[ret - i++] = ft_baseset(option->spec)[nbr % option->nbr_base];
		nbr /= option->nbr_base;
	}
	return (buffer_len);
}

int	ft_print_nbr(unsigned long long nbr, t_options *option)
{
	char	*buffer;
	int		buffer_len;
	int		ret;

	if (option->spec == 'x' || option->spec == 'X' || option->spec == 'p')
		option->nbr_base = 16;
	if ((option->spec == 'd' || option->spec == 'i') && (int)nbr < 0)
	{
		option->sign = -1;
		nbr = -nbr;
	}
	buffer_len = ft_put_precision(nbr, option, &buffer);
	buffer_len += ft_put_minus(option, &buffer);
	if (option->spec == 'p')
		buffer_len = ft_ptr_prefix(&buffer);
	ret = put_width_str(&buffer, option);
	ret += ft_put_minus1(buffer_len, option, &buffer);
	ft_putstr(buffer);
	free(buffer);
	return (ret);
}
