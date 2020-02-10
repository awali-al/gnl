/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:54:40 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/06 13:06:53 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ret_val;

	if (s)
	{
		ret_val = ft_strnew(len);
		if (ret_val)
		{
			ret_val = ft_strncpy(ret_val, &s[start], len);
			return (ret_val);
		}
	}
	return (NULL);
}
