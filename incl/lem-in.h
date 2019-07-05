/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem-in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 08:56:35 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/05 16:13:00 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "../libft/incl/libft.h"
//#include <errno.h>

/*
** this list is were I store the the roomnames.
** roomvalue is a number that contains 0, 1 or 2.
** 1 for being startroom, 2 for being endroom and 0 for in between rooms.
*/

typedef struct			s_lem_list
{
	int					roomvalue;
	char				*room;
	struct s_lem_list	*next;
}						t_lem_list;

typedef struct			s_lem_hash
{
	int					id;
	char				*room;
	struct s_lem_hash	*next;
}						t_lem_hash;

typedef struct			s_data
{
	int					start;
	int					end;
	int					ants;
	int					check;
	char				*startroom;
	char				*endroom;
}						t_data;

/*
**	input
*/

void					check_start_end(char *line, t_data *vl, t_lem_list **head);
void					check_line_after_start_end(char *line);
int						check_ants(char *line, t_data *vl);
void					check_dash(char *line, t_data *vl);
void					check_room_connection(char *line);

/*
** link list
*/

void					start_list(char *line, t_lem_list *head);
void					add_to_list(char *line, t_lem_list **head, int d);

/*
** create hash table
*/

void					create_hash(t_lem_list *head);

#endif