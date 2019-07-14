/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_adjacency_list.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:31:47 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/14 12:15:16 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

static t_lem_list	*search_left_room(char *line, t_lem_hash *table, int length_list)
{
	t_lem_hash				*tmp;
	char					*roomname;
	unsigned long long		i;

	roomname = ft_strndup(line, '-');
	i = hash_sum(roomname, length_list);
	tmp = &table[i];
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->elem->room, roomname) == 0)
		{
			free(roomname);
			return (tmp->elem);
		}
		tmp = tmp->next;
	}
	free(roomname);
	return (NULL);
}

static t_lem_list	*search_right_room(char *line, t_lem_hash *table, int length_list)
{
	t_lem_hash	*tmp;
	char		*roomname;
	int			i;

	roomname = ft_strdup(ft_strchr(line, '-') + 1);
	i = hash_sum(roomname, length_list);
	tmp = &table[i];
	while (tmp != NULL)
	{
		if (tmp->elem && tmp->elem->room && ft_strcmp(tmp->elem->room, roomname) == 0)
		{
			free(roomname);
			return (tmp->elem);
		}
		tmp = tmp->next;
	}
	free(roomname);
	return (NULL);
}

static void			add_first_connection(t_lem_list *room_left, t_lem_list *room_right, t_edge *connection)
{
	if (room_left->edges == NULL)
		room_left->edges = connection;
	else
	{
		t_edge	*tmp;

		tmp = room_left->edges;
		room_left->edges = connection;
		connection->next = tmp;
	}
	connection->connects_to = room_right;
}

static void			add_second_connection(t_lem_list *room_left, t_lem_list *room_right, t_edge *connection)
{
	if (room_right->edges == NULL)
		room_right->edges = connection;
	else
	{
		t_edge	*tmp;

		tmp = room_right->edges;
		room_right->edges = connection;
		connection->next = tmp;
	}
	connection->connects_to = room_left;
}

/*
** Looking for the leftroom in the connection string.
*/

void				add_connections(char *line, t_lem_hash *table, int length_list)
{
	t_lem_list	*room_left;
	t_lem_list	*room_right;
	t_edge		*first_ptr;
	t_edge		*second_ptr;

	room_left = search_left_room(line, table, length_list);
	room_right = search_right_room(line, table, length_list);
	first_ptr = (t_edge *)ft_memalloc(sizeof(t_edge));
	second_ptr = (t_edge *)ft_memalloc(sizeof(t_edge));
	if (room_left && room_right)
	{
		add_first_connection(room_left, room_right, first_ptr);
		add_second_connection(room_left, room_right, second_ptr);
	}
	else
		error_handling(7, 2, first_ptr, second_ptr);
}
