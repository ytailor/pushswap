/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 12:00:57 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/26 17:11:46 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*ft_create_element(int value)
{
	t_list		*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	new_element->value = value;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}


t_list		*ft_insert_element_end(t_list *list, int value)
{
	t_list		*tmp;
	t_list		*new_element;

	tmp = list;
	new_element = ft_create_element(value);
	if (list == NULL)
		return (new_element);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_element;
		new_element->prev = tmp;
	}
	return (list);
}

t_list		*ft_insert_element_first(t_list *list, int value)
{
	t_list		*tmp;
	t_list		*new_element;

	tmp = list;
	new_element = ft_create_element(value);
	if (list == NULL)
		return (new_element);
	else
	{
		while (tmp->prev != NULL)
			tmp = tmp->prev;
		tmp->prev = new_element;
		new_element->next = tmp;
		list = list->prev;
	}
	return (list);
}

t_list		*ft_last_element(t_list *l_tmp)
{
	while (l_tmp->next != NULL)
		l_tmp = l_tmp->next;
	return (l_tmp);
}
