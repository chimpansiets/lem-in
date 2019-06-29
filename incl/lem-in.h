/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem-in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 08:56:35 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/29 18:55:20 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "../libft/incl/libft.h"
#include <errno.h>

typedef struct		s_data
{
	int				start;
	int				end;
	int				ants;
	char			*startchamber;
	char			*endchamber;
}					t_data;

/*
**	input
 */

void				ft_check_input(char *line, t_data *vl);

#endif