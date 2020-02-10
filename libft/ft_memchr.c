/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:46:14 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/06 11:55:24 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	o;
	size_t	i;
	char	*sc;

	o = (char)c;
	sc = (char *)s;
	i = 0;
	while (i < n)
	{
		if (sc[i] == o)
			return (&sc[i]);
		i++;
	}
	return (NULL);
}
