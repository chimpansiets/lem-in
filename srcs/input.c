/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/29 18:35:06 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/29 20:03:14 by vmulder       ########   odam.nl         */
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

void	ft_check_connect(char *line) // later add linklist
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (line[0] == '#')
		count++;
	else if (line[0] != '#')
	{
		while (line[i])
		{
			if (line[i] == '-')
				count++;
			i++;
		}
	}
	if (count != 1)
	{
		ft_printf("Error: There is a problem linking rooms\n");
		free(line);
		exit(1);
	}
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
		ft_printf("Error: The number of ants is incorrect\n");
		free(line);
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
		ft_printf("Error: empty line after start or end.");
		exit(1);
	}
	else if (line[0] == '#')
	{
		free(line);
		ft_printf("Error: comment after start or end.");
		exit(1);
	}
}

void	ft_check_start_end(char *line, t_data *vl)
{
	if (ft_strncmp("start", &line[2], 5) == 0 && line[7] == '\0')
	{
		vl->start++;
		get_next_line(3, &vl->startchamber);
		ft_check_line_after_start_end(vl->startchamber);
	}
	else if (ft_strncmp("end", &line[2], 3) == 0 && line[5] == '\0')
	{
		vl->end++;
		get_next_line(3, &vl->endchamber);
		ft_check_line_after_start_end(vl->endchamber);
	}
}

/*
** calls the other checks and make sure that there are no white lines.
*/

void	ft_check_input(char *line, t_data *vl)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		ft_printf("Error: empty lines in file.");
		exit(1);
	}
	if (vl->start == 0 && line[0] != '#')
		ft_check_ants(line, vl);
	if (line[0] == '#' && line[1] == '#')
		ft_check_start_end(line, vl);
	if (vl->start == 1 && vl->end == 1)
		ft_check_connect(line);
}
