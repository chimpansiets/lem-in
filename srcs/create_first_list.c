/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_first_list.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 08:27:14 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/12 16:48:12 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

static char				*ft_getroomname(char *line)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char*)ft_memalloc(sizeof(char) * ft_strlen(line));
	while (line[i] && line[i] != ' ' && line[i] != '\t')
	{
		ret[i] = line[i];
		i++;
	}
	return (ret);
}

/*
** it will create a new node and put the line which represents the room name in
** the node, also the number.
*/

static t_lem_list	*origin_node(char *line, int d)
{
	t_lem_list	*new_node;
	char		*roomname;

	new_node = (t_lem_list *)ft_memalloc(sizeof(t_lem_list));
	roomname = ft_getroomname(line);
	new_node->room = roomname;
	new_node->roomvalue = d;

	return (new_node);
}

/*
** It will call function origin_node to create a new node.
** then this new node will point to the current head node.
** in the last line we make the headnote contain the newest node.
*/

static void			insert_node(char *line, t_lem_list **head, int d)
{
	t_lem_list	*new_node;

	new_node = origin_node(line, d);
	new_node->next = *head;
	*head = new_node;
}

/*
** It receives the address of the headnode in this function, if its the first
** time it will call the function origin_node and make the value of the
** headnode contain the data of the new_node. If there is already data in 
** head node it will go to the insert_node function.
*/

void				add_to_list(char *line, t_lem_list **head, int d)
{
	if (head == NULL) // *head or head not sure...
		*head = origin_node(line, d);
	else
		insert_node(line, head, d);
	// display(*head);
}
