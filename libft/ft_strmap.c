/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:06:36 by smouzdah          #+#    #+#             */
/*   Updated: 2019/03/30 12:41:58 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			ret_val[i] = f(s[i]);
	}
	return (ret_val);
}
