/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:20:52 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/28 11:49:26 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_ascending(t_list *l_a)
{
	if (l_a == NULL)
		return (0);
	while (l_a->value < (l_a->next)->value)
	{
		l_a = l_a->next;
		if (l_a->next == NULL)
			return (1);
	}
	return (0);
}

int			ft_descending(t_list *l_b)
{
	if (l_b == NULL)
		return (1);
	while (l_b->value > (l_b->next)->value)
	{
		l_b = l_b->next;
		if (l_b->next == NULL)
			return (1);
	}
	return (0);
}

t_list		*ft_rotate_a(t_list *l_a, t_list *l_b)
{
	t_list		*last;

	last = ft_last_element(l_a);
	last->next = l_a;
	(l_a->next)->prev = NULL;
	l_a->next = NULL;
	l_a->prev = last;
	while (l_a->prev != NULL)
		l_a = l_a->prev;
	if ((ft_ascending(l_a) == 1) && l_b == NULL)
		ft_putstr("ra\n");
	else
		ft_putstr("ra ");
	return (l_a);
}

t_list		*ft_rotate_b(t_list *l_b)
{
	t_list		*last;

	last = ft_last_element(l_b);
	last->next = l_b;
	(l_b->next)->prev = NULL;
	l_b->prev = last;
	l_b->next = NULL;
	while (l_b->prev != NULL)
		l_b = l_b->prev;
	ft_putstr("rb ");
	return (l_b);
}
