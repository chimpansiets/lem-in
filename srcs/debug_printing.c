/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_printing.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 15:50:32 by svoort         #+#    #+#                */
/*   Updated: 2019/07/13 14:42:47 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

void	print_connections(t_lem_hash *table, int length)
{
	t_edge	*tmp;
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
		ft_printf("%s\n", table[i].elem->room);
		tmp = table[i].elem->edges;
		while (tmp)
		{
			ft_printf("connects to %s\n", tmp->connects_to->room);
			tmp = tmp->next;
		}
		i++;
	}
}
