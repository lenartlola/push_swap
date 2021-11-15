/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:43:04 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/15 12:43:05 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(t_node *a)
{
	int	current;
	t_node	*tmp;

	while (a->next)
	{
		tmp = a->next;
		current = a->value;
		while (tmp)
		{
			if (tmp->value == current)
				ft_error();
			if (tmp->next)
				tmp = tmp->next;
			else
				break;
		}
		a = a->next;
	}
	while (a->prev)
		a = a->prev;
}
