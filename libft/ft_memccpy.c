/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:10:25 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/06 11:47:57 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			o;
	char			*dstc;
	char			*srcc;

	o = (char)c;
	i = 0;
	dstc = (char *)dst;
	srcc = (char *)src;
	while (i < n)
	{
		dstc[i] = srcc[i];
		if (dstc[i] == o)
			return (&dstc[i + 1]);
		i++;
	}
	return (NULL);
}
