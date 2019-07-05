/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_hash_table.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 08:27:14 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/05 16:14:21 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

/*
** checking the length of linked list.
*/

int		length_linked_list(t_lem_list *head)
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
** ???
*/

void	create_hash(t_lem_list *head)
{
	//t_lem_hash *hnode;
	length_linked_list(head);
}