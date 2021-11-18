/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:12:58 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/09 10:32:10 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_width_str(char **buffer, t_options *option)
{
	char	*width;
	int		i;

	if (option->width <= (int)ft_strlen(*buffer))
		return ((int)ft_strlen(*buffer));
	width = (char *)malloc(sizeof(char)
			* (option->width - ft_strlen(*buffer) + 1));
	i = 0;
	while ((size_t)i < option->width - ft_strlen(*buffer))
	{
		if (option->zero == 1)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (option->negative == 0)
		*buffer = ft_strjoin(width, *buffer, 3);
	else
		*buffer = ft_strjoin(*buffer, width, 3);
	return (option->width);
}

char	*parse_buffer(char *str, int end, int len)
{
	int		i;
	char	*buffer;

	if (end > len)
		end = len;
	buffer = (char *)malloc(sizeof(char) * end + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < end)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

int	ft_print_str(char *str, t_options *option)
{
	int		ret;
	char	*buffer;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	if (option->precision == -1 || (size_t)option->precision > ft_strlen(str))
		option->precision = ft_strlen(str);
	buffer = parse_buffer(str, option->precision, ft_strlen(str));
	ret = put_width_str(&buffer, option);
	ft_putstr(buffer);
	free(buffer);
	return (ret);
}
