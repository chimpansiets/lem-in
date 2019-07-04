/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/29 18:35:06 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/04 16:41:07 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

/*
** in check start and end those get malloc'd so make sure to free after i dont
** need them anymore.
*/

/*
** this function checks after finding start and end room that they are correct
** connected with a - symbol
*/

int		ft_check_room_connections(char *line) // later add to linklist
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
	if (count != 1)
		return (0);
	return (1);
}

/*
** this function checks if you give a valid ant amount
*/

void	ft_check_ants(char *line, t_data *vl)
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
		ft_printf("Error: The number of ants is incorrect.\n");
		exit(1);
	}
}

/*
** this function checks if there is only one ##start and ##end
** maybe make sure there is no comment below this.
*/

void	ft_check_line_after_start_end(char *line)
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

void	ft_check_start_end(char *line, t_data *vl, t_lem_list **head)
{
	if (ft_strncmp("start", &line[2], 5) == 0 && line[7] == '\0')
	{
		vl->start++;
		get_next_line(3, &vl->startroom);
		ft_check_line_after_start_end(vl->startroom);
		ft_add_to_list(vl->startroom, head, 1);
	}
	else if(ft_strncmp("end", &line[2], 3) == 0 && line[5] == '\0')
	{
		vl->end++;
		get_next_line(3, &vl->endroom);
		ft_check_line_after_start_end(vl->endroom);
		ft_add_to_list(vl->endroom, head, 2);
	}
	else if (line[0] != '#')
	{
		ft_add_to_list(line, head, 0);
	}
}

/*
** calls the other checks and make sure that there are no white lines.
** if the start command is not yet called it will go in			-> first if.
** the startcommand is 1 but the end  is 0 (so chambernames)	-> second if.
** when startcommand is 1 and end is 1 (so chamberconnections)	-> thirth if.
*/

void	ft_check_input(char *line, t_data *vl, t_lem_list **node)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		ft_printf("Error: empty lines in file.\n");
		exit(1);
	}
	else if (vl->ants == 0)
		ft_check_ants(line, vl);
	else if (!ft_check_room_connections(line))
		ft_check_start_end(line, vl, node);

}
