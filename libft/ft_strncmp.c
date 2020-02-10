/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:43:21 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/02 21:39:33 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;

	if (n == 0)
		return (0);
	i = 1;
	a = s1[0];
	b = s2[0];
	while (a - b == 0 && i < n)
	{
		a = s1[i];
		b = s2[i];
		if (s1[i] == '\0' || s2[i] == '\0')
			return (a - b);
		i++;
	}
	return (a - b);
}
