/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:12:28 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/26 17:13:47 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort(t_list *l_a)
{
	t_list		*l_b;
	t_flag		flag;

	l_b = NULL;
	ft_init_flag(&flag);
	while (flag.ok == 0)
	{
		if (l_a->value > (ft_last_element(l_a))->value)
			l_a = ft_rotate_a(l_a, l_b);
		if (l_a->value > (l_a->next)->value)
			l_a = ft_swap_a(l_a, l_b);
		flag.a = ft_ascending(l_a);
		if (flag.a == 0 && (l_a->value < (l_a->next)->value))
		{
			ft_push_b(&l_a, &l_b, &flag);
			ft_sort_b(&(l_b), &flag);
		}
		while (flag.a == 1 && l_b != NULL)
		{
			ft_push_a(&l_a, &l_b, &flag);
			flag.a = ft_ascending(l_a);
		}
		if (flag.a == 1 && flag.b == 1 && l_b == NULL)
			flag.ok = 1;
	}
}

void		ft_sort_b(t_list **l_b, t_flag *flag)
{
	if ((*l_b)->next != NULL)
	{
		if ((*l_b)->value < (ft_last_element(*l_b))->value)
			*l_b = ft_rotate_b(*l_b);
		if ((*l_b)->value < ((*l_b)->next)->value)
			(*l_b) = ft_swap_b(*l_b);
		flag->b = ft_descending(*l_b);
	}
	if ((*l_b)->next == NULL)
		flag->b = 1;
}

void		ft_init_flag(t_flag *flag)
{
	flag->a = 0;
	flag->b = 1;
	flag->ok = 0;
}

void		ft_print_all(t_list *l_a, t_list *l_b, t_flag *flag)
{
	ft_printf("\nl_a = ");
	while (l_a != NULL)
	{
		ft_printf("%d ",l_a->value);
		l_a = l_a->next;
	}
	ft_printf("\nl_b = ");
	while (l_b != NULL)
	{
		ft_printf("%d ",l_b->value);
		l_b = l_b->next;
	}
	ft_printf("\nflag [a:%d] [b:%d] [ok:%d] \n", flag->a, flag->b, flag->ok);
}
