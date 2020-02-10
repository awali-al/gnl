/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:41:47 by smouzdah          #+#    #+#             */
/*   Updated: 2019/03/28 19:14:33 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *dstc;
	char *srcc;

	dstc = (char *)dst;
	srcc = (char *)src;
	if (dstc < srcc)
	{
		while (len-- > 0)
			*(dstc++) = *(srcc++);
	}
	else
	{
		while (len-- > 0)
			dstc[len] = srcc[len];
	}
	return (dst);
}
