/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:37:38 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/10 11:04:48 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Initializing the structure
void	init(t_options *option)
{
	option->negative = 0;
	option->zero = 0;
	option->width = 0;
	option->precision = -1;
	option->spec = 0;
	option->nbr_base = 10;
	option->sign = 1;
}

/*
 * Apres avoir initializer les option, et etre arriver sur un "%" et que apres "%" n'est pas un specifier, ici on determine c'est quoi l'index actuel et on change les option d'apres le flag.
 * il y a un peu de complexite de printf ici, certains flags peuvent ecraser les autres s'ils presentent.
 * plus d'info : https://www.cplusplus.com/reference/cstdio/printf/
 * 				: https://www.cypress.com/file/54441/download
*/
void	check_flags(va_list ap, char *format, t_options *option, int i)
{
	if (format[i] == '0' && option->width == 0 && option->precision == -1)
		option->zero = 1;
	else if (format[i] == '-')
		option->negative = 1;
	else if (format[i] == '.')
		option->precision = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		width_precision(ap, format, option, i);
}

/*
 * width et precision sont encore plus complexes, pour bien comprendre il faut vraiment bien comprendre le printf().
 * regarder man 3 printf
 * Ici on determine simplement les regle de width ou precision et les traite d'apres les flags
 * Si l'index actuel est un chifre et que le flag de precision n'est pas actif la valeur de width serait ce chifre. Mais si precision est actif la valeur de precision serait ce chifre.
 * Autrement si l'index est un '*' et que precision est actif 
*/
void	width_precision(va_list ap, char *format, t_options *option, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (option->precision == -1)
			option->width = option->width * 10 + format[i] - 48;
		else
			option->precision = option->precision * 10 + format[i] - 48;
	}
	else if (format[i] == '*')
	{
		if (option->precision == -1)
		{
			option->width = va_arg(ap, int);
			if (option->width < 0)
			{
				option->negative = 1;
				option->width *= -1;
			}
		}
		else
			option->precision = va_arg(ap, int);
	}	
}

// Length of a number
int	ft_nbrlen(unsigned long long nbr, t_options *option)
{
	int	i;

	if (nbr == 0 && option->precision != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		i++;
		nbr /= option->nbr_base;
	}
	return (i);
}

char	*ft_baseset(char spec)
{
	if (spec == 'u' || spec == 'd' || spec == 'i')
		return ("0123456789");
	else if (spec == 'x' || spec == 'p')
		return ("0123456789abcdef");
	else if (spec == 'X')
		return ("0123456789ABCDEF");
	return (0);
}
