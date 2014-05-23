/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 11:48:54 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/24 11:48:58 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	ft_nb_substrings(char const *s, char c)
{
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			ret++;
		i++;
	}
	return (ret);
}

static char	**ft_tab_fill(char const *s, char c, char **tab, int nb_str)
{
	size_t			i;
	size_t			sub_len;
	int				j;

	i = 0;
	j = 0;
	while (j < nb_str)
	{
		sub_len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			sub_len++;
		}
		tab[j] = ft_strsub(s, i - sub_len, sub_len);
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**tab;
	int				nb_str;

	if (!s)
		return (NULL);
	nb_str = ft_nb_substrings(s, c);
	tab = (char**)malloc(sizeof(char *) * nb_str + 1);
	if (tab)
		tab = ft_tab_fill(s, c, tab, nb_str);
	return (tab);
}
