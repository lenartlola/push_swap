/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:48:56 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/08 11:51:30 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

# define SPEC "cspdiuxX%"

typedef struct s_otions
{
	int		negative;
	int		zero;
	int		width;
	int		precision;
	char	spec;
	int		nbr_base;
	int		sign;
}	t_options;

int		ft_printf(const char *format, ...);
int		parse_format(va_list ap, char *format);
void	check_flags(va_list ap, char *format, t_options *option, int i);
void	width_precision(va_list ap, char *format, t_options *option, int i);
int		ft_print(va_list ap, t_options *option);
int		ft_print_c(int c, t_options *option);
int		put_width_c(int width, int len, int zero);
int		ft_print_str(char *str, t_options *option);
int		put_width_str(char **buffer, t_options *option);
char	*parse_buffer(char *str, int end, int len);
int		ft_print_nbr(unsigned long long nbr, t_options *option);
int		ft_put_precision(unsigned long long nbr,
			t_options *option, char **buffer);
int		ft_put_minus(t_options *option, char **buffer);
int		ft_put_minus1(int buffer_len, t_options *option, char **buffer);
int		ft_ptr_prefix(char **buffer);
int		ft_nbrlen(unsigned long long nbr, t_options *option);
void	init(t_options *option);
char	*ft_baseset(char spec);

#endif
