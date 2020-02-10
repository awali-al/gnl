/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smouzdah <smouzdah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:17:02 by smouzdah          #+#    #+#             */
/*   Updated: 2019/05/06 21:20:17 by smouzdah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*join_and_free(char *dst, char *src, int len, int mode)
{
	char *tmp;
	char *tmp2;

	if (mode)
	{
		tmp = ft_strjoin(dst, src);
		ft_strdel(&dst);
		return (tmp);
	}
	else
	{
		tmp = ft_strsub(src, 0, len);
		tmp2 = ft_strjoin(dst, tmp);
		ft_strdel(&dst);
		ft_strdel(&tmp);
		return (tmp2);
	}
}

static int			get_line(char *buff, int fd, char **line)
{
	char	*ret_val;
	int		len;

	ret_val = ft_strnew(0);
	while (!ft_strchr(buff, '\n'))
	{
		ret_val = join_and_free(ret_val, buff, BUFF_SIZE, 1);
		len = read(fd, buff, BUFF_SIZE);
		buff[len] = '\0';
		if (len == 0)
		{
			*ret_val != '\0' ? *line = ret_val : ft_strdel(&ret_val);
			return (!ret_val ? 0 : 1);
		}
	}
	len = ft_strchr(buff, '\n') - buff;
	ret_val = join_and_free(ret_val, buff, len, 0);
	ft_memmove(buff, ft_strchr(buff, '\n') + 1,
			ft_strlen(ft_strchr(buff, '\n') + 1) + 1);
	*line = ret_val;
	return (1);
}

static t_savefd		*newsave(int fd)
{
	t_savefd *lst;

	lst = malloc(sizeof(t_savefd));
	lst->fd = fd;
	lst->data = ft_strnew(BUFF_SIZE);
	lst->next = NULL;
	return (lst);
}

static t_savefd		*checksave(t_savefd **save, int fd)
{
	t_savefd *lst;

	lst = *save;
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		if (lst->next == NULL)
			lst->next = newsave(fd);
		lst = lst->next;
	}
	return (lst);
}

int					get_next_line(const int fd, char **line)
{
	static t_savefd	*save = NULL;
	t_savefd		*node;
	int				check;

	if (read(fd, NULL, 0) == -1)
		return (-1);
	if (fd >= 0 && line)
	{
		if (!save)
			save = newsave(fd);
		node = checksave(&save, fd);
		check = get_line(node->data, fd, line);
		if (check)
			return (1);
		return (0);
	}
	return (-1);
}
