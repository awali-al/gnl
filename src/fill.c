/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 21:24:55 by aminewalial       #+#    #+#             */
/*   Updated: 2019/06/30 17:17:34 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			free_list(t_lls *head)
{
	if (head->next)
		free_list(head->next);
	if (head->sarr)
		free(head->sarr);
	free(head);
}

static t_elem	struc_fil(char *str, int x, int y, int mx)
{
	t_elem	elem;
	char	*tmp;

	elem.x = x;
	elem.y = y;
	elem.z = ft_atoi(str);
	elem.maxw = mx;
	if ((tmp = ft_strchr(str, ',')))
		elem.color = hextodec(tmp + 1);
	else
		elem.color = 0x47CACC;
	return (elem);
}

static t_lls	*new_node(t_lls **head, char *line, int y, int mx)
{
	t_lls	*ret;
	char	**str;
	int		i;

	ret = (t_lls*)malloc(sizeof(t_lls));
	ret->next = NULL;
	ret->sarr = (t_elem*)malloc((mx + 1) * sizeof(t_elem));
	str = split_whitespaces(line);
	i = -1;
	while (++i < mx)
		if (color_ver(str[i]) == 0)
			color_error(*head);
		else
		{
			ret->sarr[i] = struc_fil(str[i], i, y, mx);
			free(str[i]);
		}
	free(str);
	return (ret);
}

static void		list_fill(t_lls **head, char **line, int y)
{
	t_lls		*tmp;
	static int	mx = -1;

	if (mx == -1)
		mx = whitelen(*line);
	if (mx != whitelen(*line))
		length_error();
	else
	{
		if (*head == NULL)
			*head = new_node(head, *line, y, mx);
		else
		{
			tmp = *head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_node(head, *line, y, mx);
		}
	}
	ft_strdel(line);
}

t_elem			**dar_fil(char *av, int *maxh)
{
	t_lls	*head;
	t_lls	*tmp;
	t_elem	**darr;
	t_file	f;
	int		y;

	if ((f.fd = open(av, O_RDONLY)) == -1)
		no_file(av);
	y = -1;
	head = NULL;
	while (get_next_line(f.fd, &(f.line)))
		list_fill(&head, &f.line, ++y);
	close(f.fd);
	tmp = head;
	darr = (t_elem**)malloc((y + 1) * sizeof(t_elem*));
	*maxh = y + 1;
	y = -1;
	while (tmp)
	{
		darr[++y] = tmp->sarr;
		tmp = tmp->next;
	}
	return (darr);
}
