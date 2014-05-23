/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msommagg <msommagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:47:30 by msommagg          #+#    #+#             */
/*   Updated: 2013/11/25 20:03:55 by msommagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_nb_char(int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		rev_n;
	char	*str;

	rev_n = ft_nb_char(n);
	str = (char *)malloc(sizeof(char) * rev_n + 1);
	if (str)
	{
		str[rev_n--] = '\0';
		if (n < 0)
			str[0] = '-';
		else if (n == 0)
			str[0] = '0';
		while (n != 0)
		{
			if (n > 0)
				str[rev_n--] = ((n % 10) + '0');
			else
				str[rev_n--] = ((-(n % 10)) + '0');
			n /= 10;
		}
	}
	return (str);
}
