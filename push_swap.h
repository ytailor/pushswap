/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 12:27:22 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/27 12:27:25 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/includes/libft.h"

typedef struct		s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct		s_flag
{
	int				a;
	int				b;
	int				ok;
}					t_flag;

int		ft_ascending(t_list *l_a);
int		ft_descending(t_list *l_b);
void	ft_init_flag(t_flag *flag);
void	ft_sort(t_list *l_a);
void	ft_sort_b(t_list **l_b, t_flag *flag);
t_list	*ft_last_element(t_list *l_tmp);
t_list 	*ft_insert_element_end(t_list *list, int value);
t_list 	*ft_insert_element_first(t_list *list, int value);
t_list	*ft_rotate_a(t_list *l_a, t_list *l_b);
t_list	*ft_rotate_b(t_list *l_b);
t_list	*ft_swap_a(t_list *l_a, t_list *l_b);
t_list	*ft_swap_b(t_list *l_b);
void	ft_push_a(t_list **l_a, t_list **l_b, t_flag *flag);
void 	ft_push_b(t_list **l_a, t_list **l_b, t_flag *flag);
void	ft_print_list(t_list *temp);
void	ft_print_all(t_list *l_a, t_list *l_b, t_flag *flag);
int		ft_check_param(char *argv);

#endif
