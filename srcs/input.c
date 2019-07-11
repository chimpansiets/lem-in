/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/29 18:35:06 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/11 22:28:50 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

/*
** in check start and end those get malloc'd so make sure to free after i dont
** need them anymore.
*/

void	check_room_connection(char *line, t_lem_hash **table, t_data vl) //add to adjacency list
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (line[0] == '#')
		count++;
	while (line[i])
	{
		if (line[i] == '-')
			count++;
		i++;
	}
	if (count == 1)
	{
		add_to_adjacency_list(line, table, vl);// add to the current node the edge (which is the room that comes after the dash and malloc the s_edge struct for that.)
		return ;
	}
	else
	{
		free(line);
		ft_printf("Error: There is a problem with linking rooms.\n");
		exit(1);
	}
}

/*
** this function checks if the get_next_line already found the '-' symbol.
** when it finds one we set the vl->check 'on' so we know we are done with
** reading room names and can start reading room connections.
*/

void	check_dash(char *line, t_data *vl)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			count++;
		i++;
	}
	if (count == 1)
		vl->checkc = 1;
}

/*
** this function checks if you give a valid ant amount
*/

int		check_ants(char *line, t_data *vl)
{
	int i;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		vl->ants = vl->ants * 10 + line[i];
		i++;
	}
	if (line[i] != '\0')
	{
		free(line);
		ft_printf("Error: The number of ants is incorrect or missing.\n");
		exit(1);
	}
	return (1);
}

/*
** this function checks if after starting and ending room there is 
** no comment or an empty line.
*/

void	check_line_after_start_end(char *line)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		ft_printf("Error: empty line after start or end.\n");
		exit(1);
	}
	else if (line[0] == '#')
	{
		free(line);
		ft_printf("Error: comment after start or end.\n");
		exit(1);
	}
}

/*
** gets called when a line starts with double hash and then checks if its the
** the start room of the end chamber and calls the function to check them.
** also adds the roomnames to the linklist. (change to stdinput)
*/

void	check_start_end(char *line, t_data *vl, t_lem_list **head)
{
	if (ft_strncmp("start", &line[2], 5) == 0 && line[7] == '\0')
	{
		vl->start++;
		get_next_line(3, &vl->startroom);
		check_line_after_start_end(vl->startroom);
		add_to_list(vl->startroom, head, 1);
	}
	else if(ft_strncmp("end", &line[2], 3) == 0 && line[5] == '\0')
	{
		vl->end++;
		get_next_line(3, &vl->endroom);
		check_line_after_start_end(vl->endroom);
		add_to_list(vl->endroom, head, 2);
	}
	else if (line[0] != '#')
	{
		add_to_list(line, head, 0);
	}
}
