/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 08:59:33 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/30 18:04:02 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

/* 
** somehow i need to save all the rooms in a link list with the names and where
** they connect too.
*/

void	ft_lemin(void)
{
	char	*line;
	t_data	vl;
	int		fd;
	
	fd = 0;
	fd = open("input", fd, O_RDONLY);
	ft_bzero(&vl, sizeof(vl));
	while(get_next_line(fd, &line))
	{
		ft_check_input(line, &vl);
		ft_printf("%s\n", line);
		free(line);
	}
	free(line);
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