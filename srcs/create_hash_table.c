/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_hash_table.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 08:27:14 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/08 11:41:36 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"
/*
static void	display(t_lem_hash **hnode)
{
	ft_printf("ha\n");
	ft_printf("hashtable index: %d\n", hnode[1]->index);
}
*/

/*
** checking the length of linked list.
*/

static int		length_linked_list(t_lem_list *head)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	ft_printf("the length of ll: %d\n", i);
	return (i);
}

/*
** we adding indices to the hashtable nodes.
*/

static void	add_index_to_hashlist(t_lem_hash **hnode, int d)
{
	int i;

	i = 0;
	while (i >= d)
	{
		hnode[i]->index = i;
		i++;
	}
}

/*
** we set the nodes in the list to NULL.
*/

static void	initialize_hashlist(t_lem_hash **hnode, int d)
{
	int i;

	i = 0;
	while (i >= d)
	{
		hnode[i] = NULL;
		i++;
	}
}

/*
** We make a array of linked list with the 'd' as the number as indices.
*/

void	create_hash(t_lem_list *head)
{
	int d;
	t_lem_hash **hnode;
	
	d = length_linked_list(head);
	hnode = (t_lem_hash **)malloc(sizeof(t_lem_hash *) * d);
	initialize_hashlist(hnode, d);
	add_index_to_hashlist(hnode, d);
	//display(hnode);
	
}
