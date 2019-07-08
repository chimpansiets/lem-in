/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 12:43:15 by svoort         #+#    #+#                */
/*   Updated: 2019/07/08 13:42:51 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

int		hash_sum(char *key, int length)
{
	unsigned hashval;

    for (hashval = 0; *key != '\0'; key++)
        hashval = *key + 31*hashval;
    return hashval % length;
}

/*
**	In case there is a collision we use seperate chaining with linked lists.
**	If we find that there already is an entry in our bucket, we loop
**	through a seperate linked list (tmp) attached to our bucket.
**	Until we find the end, and insert a new bucket at the end of our list.
*/

void	store_entry(t_lem_list *head, int hash, t_lem_hash **buckets)
{
	if (buckets[hash]->elem == NULL)
		buckets[hash]->elem = head;
	else
	{
		t_lem_hash	*new;
		t_lem_hash	*tmp;

		new = (t_lem_hash*)malloc(sizeof(t_lem_hash));
		tmp = buckets[hash];
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->elem = head;
		new->next = NULL;
	}
}

/*
**	Loops through our linked list, and stores every room in a corresponding
**	bucket in our hashtable.
*/

void	store_entries(t_lem_list *head, t_lem_hash **buckets, int length)
{
	int	hash;

	while (head != NULL)
	{
		hash = hash_sum(head->room, length);
		store_entry(head, hash, buckets);
		head = head->next;
	}
}
