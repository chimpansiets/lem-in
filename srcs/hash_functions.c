/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 12:43:15 by svoort         #+#    #+#                */
/*   Updated: 2019/07/12 16:36:19 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

unsigned long long	hash_sum(char *key, int length)
{
	unsigned long long hashval;

	hashval = 0;
	while (*key != '\0')
	{
		hashval = *key + 31 * hashval;
		key++;
	}
	return (hashval % length);
}



/*
**	In case there is a collision we use seperate chaining with linked lists.
**	If we find that there already is an entry in our bucket, we loop
**	through a seperate linked list (tmp) attached to our bucket.
**	Until we find the end, and insert a new bucket at the end of our list.
*/

t_lem_hash	*store_entry(t_lem_list *curr, int hash, t_lem_hash *buckets)
{
	if (buckets[hash].elem == NULL)
		buckets[hash].elem = curr;
	else
	{
		t_lem_hash	*tmp;
		t_lem_hash	*new;

		new = (t_lem_hash *)ft_memalloc(sizeof(t_lem_hash));
		new->elem = curr;
		tmp = &buckets[hash];
		while(tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (buckets);
}

/*
**	Loops through our linked list, and stores every room in a corresponding
**	bucket in our hashtable.
*/

t_lem_hash	*store_entries(t_lem_list *head, t_lem_hash *buckets, int length)
{
	int			hash;
	t_lem_list	*curr;

	curr = head;
	while (curr != NULL)
	{
		hash = hash_sum(curr->room, length);
		store_entry(curr, hash, buckets);
		curr = curr->next;
	}
	return (buckets);
}
