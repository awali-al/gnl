/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:42:29 by smouzdah          #+#    #+#             */
/*   Updated: 2019/03/31 17:33:17 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	supp[11];
	char	*ret_val;
	int		i;
	int		help;

	ret_val = NULL;
	i = 0;
	help = n < 0 ? -1 : 1;
	while (!(n <= 9 && n >= -9))
	{
		supp[i++] = help * (n % 10) + 48;
		n = n / 10;
	}
	supp[i++] = help * n + 48;
	if (help == -1)
		supp[i++] = '-';
	ret_val = ft_strnew((size_t)i);
	help = 0;
	if (ret_val)
		while (i-- > 0)
			ret_val[help++] = supp[i];
	return (ret_val);
}
