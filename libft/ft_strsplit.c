/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:30:41 by smouzdah          #+#    #+#             */
/*   Updated: 2019/03/31 21:11:14 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy(const char *source, char c)
{
	int		i;

	i = 0;
	while (source[i] != c)
		i++;
	return (ft_strsub(source, 0, i));
}

static char	*word(int index, const char *str, char c)
{
	while (index >= 0)
	{
		while (*str == c && index >= 0)
			str++;
		index--;
		while (*str != c && index >= 0)
			str++;
	}
	return (copy(str, c));
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	int		i;
	char	**ret_val;

	ret_val = NULL;
	if (s)
	{
		words = ft_wordcount(s, c);
		i = -1;
		ret_val = (char **)malloc(sizeof(ret_val) * words + 1);
		if (ret_val)
		{
			while (++i < words)
				ret_val[i] = word(i, s, c);
			ret_val[i] = 0;
		}
	}
	return (ret_val);
}
