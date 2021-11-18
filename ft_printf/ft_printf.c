/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:39:18 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/09 15:57:31 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(va_list ap, t_options *option)
{
	int		ret;
	char	spec;

	ret = 0;
	spec = option->spec;
	if (spec == 'c')
		ret = ft_print_c(va_arg(ap, int), option);
	else if (spec == '%')
		ret = ft_print_c('%', option);
	else if (spec == 's')
		ret = ft_print_str(va_arg(ap, char *), option);
	else if (spec == 'd' || spec == 'i')
		ret = ft_print_nbr(va_arg(ap, int), option);
	else if (spec == 'x' || spec == 'X' || spec == 'u')
		ret = ft_print_nbr(va_arg(ap, unsigned int), option);
	else if (spec == 'p')
		ret = ft_print_nbr(va_arg(ap, unsigned long long), option);
	return (ret);
}

void	zero_logic(t_options *option, char format)
{
	option->spec = format;
	if ((option->negative == 1 || option->precision > -1)
		&& option->spec != '%')
		option->zero = 0;
}

/*
 * Initialier nos option dabord et puis allouer la memoire a cette taille.
 * 	Si l'allocation de memoire echoue return -1.
 * Iterer tant qu'il y a une chaine de chars.
 * 	Afficher char par char tant qu'il y a pas de "%" et qu'on est pas a la fin de la chaine.
 * 	Si l'index sur lequel on est, est un "%";
 * 		Initializer les option; [zero = 0, width = 0, precision = -1, spec = 0, nbr_base = 10, sign = 1,]
 * 		Tant que l'index suivant n'est pas la fin de la chaine de chars et que l'index sur lequel on est, n'est pas un des specifiers;
 * 			check_flag();
*/

int	parse_format(va_list ap, char *format)
{
	int			i;
	int			ret;
	t_options	*option;

	i = 0;
	ret = 0;
	option = malloc(sizeof(t_options) * 1);
	if (!(option))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ret += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init(option);
			while (format[++i] != '\0' && !(ft_strchr(SPEC, format[i])))
				check_flags(ap, format, option, i);
			zero_logic(option, format[i++]);
			ret += ft_print(ap, option);
		}
	}
	free(option);
	return (ret);
}

/*
 * L'entree de fonction, on appel tout de suite la fonction parse_format()
*/

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = parse_format(ap, (char *)format);
	va_end(ap);
	return (ret);
}
