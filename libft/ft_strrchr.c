/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:02:03 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/06 13:11:22 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret_val;
	int		i;

	ret_val = NULL;
	if (s[0] == c)
		ret_val = (char *)s;
	i = 0;
	while (s[i++] != '\0')
	{
		if (s[i] == c)
			ret_val = (char *)s + i;
	}
	return (ret_val);
}
