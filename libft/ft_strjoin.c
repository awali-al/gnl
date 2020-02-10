/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:23:30 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/03 12:44:11 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret_val;

	ret_val = NULL;
	if (s1 && s2)
		ret_val = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (ret_val)
	{
		ret_val = ft_strncpy(ret_val, s1, ft_strlen(s1));
		ret_val = ft_strncat(ret_val, s2, ft_strlen(s2));
		return (ret_val);
	}
	return (ret_val);
}
