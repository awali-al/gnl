/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:14:05 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/02 21:37:07 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t sizedst;
	size_t i;
	size_t ret_val;

	if (size == 0)
		return (ft_strlen(src));
	sizedst = ft_strlen(dst);
	i = 0;
	if (size < sizedst)
		ret_val = ft_strlen(src) + size;
	else
		ret_val = ft_strlen(src) + ft_strlen(dst);
	while (src[i] && sizedst < size - 1)
	{
		dst[sizedst] = src[i];
		i++;
		sizedst++;
	}
	dst[sizedst] = '\0';
	return (ret_val);
}
