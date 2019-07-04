/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 08:59:33 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/04 16:40:21 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

/* 
** they connect too. (change fd to 0 because gonna read std input)
*/

/*
** lemin is the loop to read all the input and to call the function that is
** going to check the input. after the loop is done it checks if it found
** 1 starting and 1 ending room for the ants.
** vl is a struct where i save the data that i read from the file.
** bh is going to be the first link list to save the rooms before i hash them.
*/

void	ft_lemin(void)
{
	t_lem_list	*head;
	char		*line;
	t_data		vl;
	int			fd;
	
	fd = 0;
	head = NULL;
	fd = open("input", fd, O_RDONLY);
	ft_bzero(&vl, sizeof(t_data));
	while(get_next_line(fd, &line))
	{
		ft_check_input(line, &vl, &head);
//		ft_printf("%s\n", line);
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