/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_hash_table.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 08:27:14 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/08 13:35:33 by svoort        ########   odam.nl         */
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
** we set the nodes in the list to NULL.
*/

static void	initialize_hashtable(t_lem_hash **buckets, int length)
{
	int i;

	i = 0;
	while (i >= length)
	{
		buckets[i] = NULL;
		i++;
	}
}

/*
** We make a array of linked list with the 'd' as the number as indices.
*/

void	create_hash(t_lem_list *head)
{
	int			length;
	t_lem_hash	**buckets;
	
	length = length_linked_list(head);
	buckets = (t_lem_hash **)malloc(sizeof(t_lem_hash *) * length);
	initialize_hashtable(buckets, length);
	store_entries(head, buckets, length);
	//display(hnode);
}
