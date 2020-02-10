/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:09:27 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/06 12:34:26 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *ret_val;

	ret_val = (char *)malloc((ft_strlen(s1) + 1) * sizeof(*ret_val));
	if (!ret_val)
		return (NULL);
	ret_val = ft_strcpy(ret_val, s1);
	return (ret_val);
}
