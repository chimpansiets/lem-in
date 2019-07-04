/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem-in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 08:56:35 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/04 16:39:14 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "../libft/incl/libft.h"
#include <errno.h>

typedef struct			s_lem_list
{
	int					roomvalue;
	char				*room;
	struct s_lem_list	*next;
}						t_lem_list;

typedef struct			s_data
{
	int					start;
	int					end;
	int					ants;
	char				*startroom;
	char				*endroom;
}						t_data;

/*
**	input
*/

void					ft_check_input(char *line, t_data *vl, t_lem_list **node);

/*
** link list
*/

void					ft_start_list(char *line, t_lem_list *head);
void					ft_add_to_list(char *line, t_lem_list **head, int d);

#endif