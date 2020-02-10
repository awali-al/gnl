/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:20:03 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/06 13:01:06 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ret_val;

	ret_val = malloc(size + 1);
	if (ret_val)
	{
		ret_val = ft_memset(ret_val, '\0', size + 1);
		return (ret_val);
	}
	else
		free(ret_val);
	return (NULL);
}
