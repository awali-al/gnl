/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:28:04 by smouzdah          #+#    #+#             */
/*   Updated: 2019/03/28 16:01:25 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dstc;
	char *srcc;

	dstc = (char *)dst;
	srcc = (char *)src;
	while (n-- > 0)
		dstc[n] = srcc[n];
	return (dst);
}
