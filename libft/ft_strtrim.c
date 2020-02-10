/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:47:27 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/03 12:40:42 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret_val;
	size_t	begin;
	size_t	end;

	ret_val = NULL;
	if (s)
	{
		begin = 0;
		end = ft_strlen(s) - 1;
		while (ft_isspace(s[begin]) && begin <= end)
			begin++;
		while (ft_isspace(s[end]) && end > 0)
			end--;
		if (end < begin)
			ret_val = ft_strnew(0);
		else
			ret_val = ft_strsub(s, (unsigned int)begin, end - begin + 1);
	}
	return (ret_val);
}
