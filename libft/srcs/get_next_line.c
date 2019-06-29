/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 10:56:18 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/29 16:33:12 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This functions tries to find the list item that has the buffer or
** the remainder of the buffer in it. This list has values str, str_len,
** fd and a pointer to the next item in the list, which is for a different
** file descriptor.
** First it checks if there is a first item of the list, and if that is true
** it checks if the value of the file descriptor matches. If that is true we
** have our list.
** However if this is not the case it will loop until we find a list item
** that matches our file descriptor.
** If the while loop completes then there is no list item found, it will
** create one. It will then also allocate space in the str for BUFF_SIZE.
** If there was no first lisst it will set the firstlist to the new list
** else it will point to it from the last list item.
*/

static t_gnl_list	*get_fd_list(ssize_t fd, t_gnl_list **firstlist)
{
	t_gnl_list *list;
	t_gnl_list *new;

	list = *firstlist;
	if (list != NULL && list->fd == fd)
		return (*firstlist);
	while (list != NULL && list->next != NULL)
	{
		if (list->next->fd == fd)
			return (list->next);
		list = list->next;
	}
	if (
		(new = (t_gnl_list*)ft_memalloc(sizeof(t_gnl_list))) == NULL ||
		(new->str = (char*)ft_memalloc(BUFF_SIZE)) == NULL)
		return (NULL);
	new->fd = fd;
	return (list == NULL
	?
	(*firstlist = new)
	:
	(list->next = new));
}

/*
** This functions frees a list item. We also pass the pointer to the pointer
** to the pointer to the first list. This way if the item that needs to be
** freed is the first list item, we should point the first list item to the
** second list item (which is now first). If it doesn't find a match on fd
** it will keep looping.
** If we find that the next item is the item to free, we make sure our
** current element will point to the one after that. Even if it's NULL.
** Then we use memdel to free all the memory at that place.
*/

static void			free_fd_item(t_gnl_list **firstlist, t_gnl_list *item)
{
	t_gnl_list			*to_free;

	to_free = *firstlist;
	while (to_free->next != NULL && to_free->next->fd != item->fd)
		to_free = to_free->next;
	if (to_free->next == item)
		to_free->next = to_free->next->next;
	else
		*firstlist = item->next;
	ft_memdel((void **)&(item->str));
	ft_memdel((void **)&item);
}

/*
** This function copies data to the line, we use this in get_from_item
** it allocates, then it copies the data from line to new_line, then it
** adds the data from add (add_len) bytes.
** then it frees line and then it sets *line to the new line.
*/

static char			*cpy_to_line(char **line, ssize_t *len, char *add,
		ssize_t add_len)
{
	char *new_line;

	new_line = ft_strnew(*len + add_len);
	if (new_line == NULL)
		return (NULL);
	ft_memcpy(new_line, *line, *len);
	ft_memcpy(new_line + *len, add, add_len);
	*len += add_len;
	if (line != NULL && *line != NULL)
		ft_strdel(line);
	*line = new_line;
	return (new_line);
}

/*
** This function copies data from the list item str field to line.
** if the string does not contain a \n we add str_len to the len
** of the line and we copy the data to line. This will return zero
** so in our main function we know we don't have a complete line yet.
** If this is all not the case (so we do find a \n), we copy data to
** line and we move the data that we didn't copy to the front of str
** in the list item and we decrease the value of str_len.
*/

static int			get_from_item(char **line, t_gnl_list *item, ssize_t *len)
{
	ssize_t lbc;

	lbc = 0;
	if (item->str_len == -1)
		return (-1);
	while (lbc < item->str_len && item->str[lbc] != '\n')
		lbc++;
	if (lbc == item->str_len)
	{
		if (cpy_to_line(line, len, item->str, item->str_len) == NULL)
			return (-1);
		len += item->str_len;
		return (0);
	}
	else
	{
		if (cpy_to_line(line, len, item->str, lbc) == NULL)
			return (-1);
		ft_memmove(item->str, item->str + lbc + 1,
				item->str_len - (lbc + (ssize_t)1));
		item->str_len -= lbc + (ssize_t)1;
		return (1);
	}
}

/*
** First we check if the input and a program setting is false.
** Then we allocate 1 byte for *line because if the data is on
** the stack memory it can't be freed (which we always) do. The
** data that was already there was removed before so that's no
** problem.
** Then we try to find our list item for this FD, read comments
** above for more info.
** Then we try to get data from the list item, read comments above
** for more info.
** Then we read the buffer until we have found a newline, read
** comments above for more info.
** If this was the last line we return -1 and free the list item.
** We return 1 if we read a line and 0 if we are done reading,
** so when len == 0.
*/

int					get_next_line(const int fd, char **line)
{
	static t_gnl_list	*firstlist;
	t_gnl_list			*item;
	ssize_t				len;
	int					ret;

	len = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE < 1 ||
	((*line = ft_strnew(0)) == NULL) ||
	((item = get_fd_list(fd, &firstlist)) == NULL))
		return (-1);
	ret = get_from_item(line, item, &len);
	if (ret != 0)
		return (ret);
	while (
		(item->str_len = read(fd, item->str, BUFF_SIZE)) != 0)
	{
		ret = get_from_item(line, item, &len);
		if (ret == -1)
			free_fd_item(&firstlist, item);
		if (ret != 0)
			return (ret);
	}
	free_fd_item(&firstlist, item);
	return (len != 0);
}
