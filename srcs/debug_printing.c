/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_printing.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 15:50:32 by svoort         #+#    #+#                */
/*   Updated: 2019/07/14 12:17:21 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

void	print_connections(t_lem_hash *table, int length)
{
	t_edge		*tmp1;
	t_lem_hash	*tmp2;
	int		i;

	i = 0;
	ft_printf("\n");
	while (i < length)
	{
		if (!table[i].elem)
		{
			i++;
			continue ;
		}
		tmp2 = &table[i];
		while (tmp2)
		{
			ft_printf("Room: %s\n", tmp2->elem->room);
			tmp1 = tmp2->elem->edges;
			while (tmp1)
			{
				ft_printf("connects to %s\n", tmp1->connects_to->room);
				tmp1 = tmp1->next;
			}
			tmp2 = tmp2->next;
		}
		i++;
	}
}
