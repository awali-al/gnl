/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:20:00 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/04 15:07:34 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeli(t_list **alst, size_t index)
{
	t_list	*supp1;
	t_list	*supp2;

	supp1 = NULL;
	supp2 = NULL;
	if (alst)
	{
		supp1 = *alst;
		supp2 = supp1->next;
		if (index == 0)
			free(supp1);
		else if (supp2)
		{
			index--;
			while (index-- && supp2->next)
			{
				supp1 = supp2;
				supp2 = supp2->next;
			}
			supp1->next = supp2->next;
			free(supp2);
		}
	}
}
