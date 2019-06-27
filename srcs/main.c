/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 08:59:33 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/27 16:55:47 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

/* 
** somehow i need to save all the rooms in a link list with the names and where
** they connect too.
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
		exit(1);
	}
}

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
		exit(1);
	}
}

void	ft_check_start_end(char *line, t_data *vl)
{
	if (ft_strncmp("start", &line[2], 5) == 0 && line[7] == '\0')
	{
		vl->start++;
		// het is de end kamer volgende line
	}
	else if (ft_strncmp("end", &line[2], 3) == 0 && line[5] == '\0')
	{
		vl->end++;
		// het is de end kamer volgende line
	}
	else
	{
		ft_printf("Error: something wrong with double hash\n");
		exit(1);
	}
}

void	ft_lemin(void)
{
	t_data	vl;
	char	*line;

	ft_bzero(&vl, sizeof(vl));
	while(get_next_line(0, &line))
	{
		if (vl.start == 0 && line[0] != '#')
			ft_check_ants(line, &vl);
		if (line[0] == '#' && line[1] == '#')
			ft_check_start_end(line, &vl);
		if (vl.start == 1 && vl.end == 1)
			ft_check_connect(line);
		
		ft_printf("%s\n", line);
	}
	if (vl.start != 1 || vl.end != 1)
	{
		ft_printf("Error: Either end or start room is missing.\n");
		exit(1);
	}
}


int main(void)
{
	ft_lemin();
	return(0);
}