/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:42:45 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/02 21:23:05 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret_val;
	t_list *supp;

	if (!lst)
		return (NULL);
	ret_val = f(lst);
	supp = ret_val;
	lst = lst->next;
	while (lst)
	{
		supp->next = f(lst);
		lst = lst->next;
		supp = supp->next;
	}
	supp->next = NULL;
	return (ret_val);
}
