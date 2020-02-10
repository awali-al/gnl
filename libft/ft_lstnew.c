/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:42:33 by smouzdah          #+#    #+#             */
/*   Updated: 2019/04/02 21:24:49 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret_val;

	ret_val = NULL;
	ret_val = (t_list *)malloc(sizeof(*ret_val));
	if (ret_val)
	{
		if (!content)
		{
			ret_val->content = NULL;
			ret_val->content_size = 0;
		}
		else
		{
			ret_val->content = malloc(content_size);
			if (ret_val->content)
				ret_val->content = ft_memcpy(ret_val->content, content,
						content_size);
			ret_val->content_size = content_size;
		}
		ret_val->next = NULL;
	}
	return (ret_val);
}
