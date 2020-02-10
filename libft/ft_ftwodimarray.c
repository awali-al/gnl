/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftwodimarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:17:08 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/03 15:22:05 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ftwodimarray(int **arr, size_t len)
{
	size_t i;

	i = 0;
	if (arr)
	{
		while (i < len)
			free(arr[i]);
		free(arr);
	}
}
