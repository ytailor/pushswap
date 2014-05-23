/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 11:49:09 by ytailor           #+#    #+#             */
/*   Updated: 2013/12/24 11:49:10 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_final_str_len(char const *s1, char const *s2)
{
	if (s1 && !s2)
		return (ft_strlen(s1));
	else if (!s1 && s2)
		return (ft_strlen(s2));
	else if (!s1 && !s2)
		return (0);
	return (ft_strlen(s1) + ft_strlen(s2));
}

static void		ft_fill_str_w_s2(char *str, char const *s2, int start)
{
	int		i;

	i = 0;
	if (s2)
	{
		while (s2[i])
		{
			str[start + i] = s2[i];
			i++;
		}
	}
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	int		i;

	len = ft_final_str_len(s1, s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str)
	{
		i = 0;
		if (s1)
		{
			while (s1[i])
			{
				str[i] = s1[i];
				i++;
			}
		}
		ft_fill_str_w_s2(str, s2, i);
		str[len] = '\0';
	}
	return (str);
}
