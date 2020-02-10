/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:47:02 by awali-al          #+#    #+#             */
/*   Updated: 2019/07/01 16:10:30 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_pow(int n, int p)
{
	int		res;
	int		i;

	if (p == 0)
		return (1);
	else
	{
		i = -1;
		res = 1;
		while (++i < p)
			res *= n;
		return (res);
	}
}

int		is_hex(char c)
{
	int		r;

	if (c >= '0' && c <= '9')
		r = c - '0';
	else if (c >= 'A' && c <= 'F')
		r = c - 'A' + 10;
	else if (c >= 'a' && c <= 'f')
		r = c - 'a' + 10;
	else
		return (-1);
	return (r);
}

int		hextodec(char *str)
{
	int		res;
	int		i;
	int		n;
	int		bn;

	i = 0;
	n = ft_strlen(str);
	res = 0;
	while (--n >= 0)
		if (str[n] == 'x')
			n = -1;
		else if ((bn = is_hex(str[n])) < 0)
			return (-1);
		else
		{
			res += bn * ft_pow(16, i);
			i++;
		}
	return (res);
}
