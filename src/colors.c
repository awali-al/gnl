/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:54:21 by awali-al          #+#    #+#             */
/*   Updated: 2019/06/27 21:18:36 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*zero_x(char *tmp)
{
	if (tmp[0] == '0')
		if (tmp[1] == 'x')
			return (tmp + 2);
		else
			return (NULL);
	else
		return (tmp);
}

int		color_ver(char *str)
{
	char	*tmp;
	int		j;

	if ((tmp = ft_strchr(str, ',')) != NULL)
	{
		if ((tmp = zero_x(tmp + 1)) == NULL)
			return (0);
		j = 0;
		while (tmp[j])
		{
			if (is_hex(tmp[j]) < 0 || j == 6)
				return (0);
			j++;
		}
	}
	return (1);
}
