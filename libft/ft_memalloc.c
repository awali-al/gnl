/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:39:24 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/06 11:47:02 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ret_val;

	ret_val = malloc(size);
	if (ret_val)
	{
		ft_bzero(ret_val, size);
		return (ret_val);
	}
	return (NULL);
}
