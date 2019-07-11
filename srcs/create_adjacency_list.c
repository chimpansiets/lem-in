/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_adjacency_list.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:31:47 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/11 22:40:17 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

/*
** Looking for the leftroom in the connection string.
** yo sietse als je toevallig vrijdag op codam bent en aan de code werkt.
** en ik er nog niet ben ik was hier gebleven (ja niet zoveel gedaan xd).
** zal ook wel in plan le campagne schrijven.
*/

void		search_left_room(char *line, t_lem_hash **table, t_data vl)
{
	char	*roomname;
	int		i;

	roomname = ft_strndup(line, '-');
	i = hash_sum(roomname, vl.length);
	while (table[i] != NULL)
	{
		if (ft_strcmp(table[i]->elem->room, roomname == 0))
		{
			// ga hier de node naar de room laten pointen die 
			// we nog moeten vinden.
		} 
	}
	free(roomname);
}

void		add_to_adjacency_list(char *line, t_lem_hash **table, t_data vl)
{
	search_left_room(line, table, vl);
}

static t_lem_list	*origin_node(char *line, int d)
{
	t_lem_list *new_node;

	new_node = (t_lem_list *)malloc(sizeof(t_lem_list));
	new_node->room = ft_strdup(line);
	new_node->roomvalue = d;
	new_node->next = NULL;

	return (new_node);
}

static void	insert_node(char *line, t_lem_list **head, int d)
{
	t_lem_list *new_node;

	new_node = origin_node(line, d);
	new_node->next = *head;
	*head = new_node;
}
