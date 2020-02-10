/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:06:36 by smouzdah          #+#    #+#             */
/*   Updated: 2019/03/30 12:42:17 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ret_val;

	ret_val = NULL;
	if (s)
		ret_val = ft_strnew(ft_strlen(s));
	if (ret_val)
	{
		i = -1;
		while (s[++i])
			ret_val[i] = f(i, s[i]);
	}
	return (ret_val);
}
