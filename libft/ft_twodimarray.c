/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twodimarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:06:52 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/03 15:13:19 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_twodimarray(size_t r, size_t c)
{
	int		**ret_val;
	size_t	i;

	ret_val = NULL;
	i = 0;
	if (r && c)
	{
		ret_val = (int **)malloc(r * sizeof(int *));
		while (i < r)
		{
			ret_val[i] = malloc(c * sizeof(int));
			i++;
		}
	}
	return (ret_val);
}
