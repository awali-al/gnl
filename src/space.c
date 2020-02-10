/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 22:54:31 by aminewalial       #+#    #+#             */
/*   Updated: 2019/06/18 01:13:18 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		white(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

int		whitelen(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (white(str[i]))
		i++;
	while (str[i] && str[i + 1])
	{
		if (white(str[i]) && !white(str[i + 1]))
			n++;
		i++;
	}
	return (n + 1);
}

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char*)malloc((n + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (i < n)
	{
		if (s1[i])
			d[i] = s1[i];
		else
			d[i] = '\0';
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	**split_whitespaces(char *str)
{
	char	**aos;
	int		n;
	int		i;
	int		j;

	i = 0;
	n = whitelen(str);
	aos = (char**)malloc((n + 1) * sizeof(char*));
	while (i < n)
	{
		j = 0;
		while (white(str[j]) == 1)
			str++;
		while (white(str[j]) == 0 && str[j])
			j++;
		aos[i] = ft_strndup(str, j);
		str += j;
		i++;
	}
	aos[i] = NULL;
	return (aos);
}
