/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_adjacency_list.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:31:47 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/11 22:14:21 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

/*
** It receives the address of the headnode in this function, if its the first
** time it will call the function origin_node and make the value of the
** headnode contain the data of the new_node. If there is already data in 
** head node it will go to the insert_node function.
*/

void		search_left_room(char *line, t_lem_hash **table)
{
	char *roomname;

	roomname = ft_strndup(line, '-');
}

void		add_to_adjacency_list(char *line, t_lem_hash **table)
{
	search_left_room(line, table);
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

/*
** It will call function origin_node to create a new node.
** then this new node will point to the current head node.
** in the last line we make the headnote contain the newest node.
*/

static void	insert_node(char *line, t_lem_list **head, int d)
{
	t_lem_list *new_node;

	new_node = origin_node(line, d);
	new_node->next = *head;
	*head = new_node;
}
