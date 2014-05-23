/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:15:42 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/28 11:57:49 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_param(char *argv)
{
	int		i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '-' && ft_isdigit(argv[i + 1]) == 0)
			return (0);
		if (argv[i] == '+' && ft_isdigit(argv[i + 1]) == 0)
			return (0);
		if (ft_isdigit(argv[i]) == 0)
		{
			if (argv[i] != '-' && argv[i] != '+')
				return (0);
		}
		i++;
	}
	return (1);
}


int			main(int argc, char **argv)
{
	t_list		*l_a;
	int			i;

	l_a = NULL;
	i = 1;
	if (argc == 2 && ft_check_param(argv[1]) == 0)
		ft_putstr("error : wrong argument\n");
	if (argc > 2)
	{
		while (argv[i])
		{
			if (ft_check_param(argv[i]) == 0)
			{
				ft_putstr("error : wrong argument\n");
				return (0);
			}
			l_a = ft_insert_element_end(l_a, ft_atoi(argv[i]));
			i++;
		}
		ft_sort(l_a);
	}
	return (0);
}
