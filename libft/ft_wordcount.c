/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:08:34 by smouzdah          #+#    #+#             */
/*   Updated: 2019/03/31 13:20:45 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(char const *s, char c)
{
	int	ret_val;
	int i;

	ret_val = 0;
	i = -1;
	while (s[++i])
	{
		if (i != 0 && s[i] == c && s[i - 1] != c)
			ret_val++;
		if (s[i + 1] == '\0' && s[i] != c)
			ret_val++;
	}
	return (ret_val);
}
