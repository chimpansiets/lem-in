/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 08:59:33 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/08 15:26:36 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

/* 
** they connect too. (change fd to 0 because gonna read std input)
*/

/*
** First checks if there are no empty lines given to this function.
** Then it calls checkants if there are no ants yet stored.
** We check for a dash, if it cant find vl->check stays zero.
** We only go in fourth if when it did not went into second if (d will be 1)
** to prevent adding the number of ants to linked list.
** when check_dash finds a dash we will set vl->check positve to know we are
** reading room conntection now and will go in the last if.
*/

void	check_input(char *line, t_data *vl, t_lem_list **head)
{
	int d;

	d = 0;
	if (ft_strlen(line) == 0)
	{
		free(line);
		ft_printf("Error: empty lines in file.\n");
		exit(1);
	}
	if (vl->ants == 0)
		d = check_ants(line, vl);
	if (line[0] != '#')
		check_dash(line, vl);
	if (!vl->check && !d)
		check_start_end(line, vl, head);
	if (vl->check)
		check_room_connection(line);
}

/*
** we going to call create_hash.
*/

void	lemin_after_retrieving_input(t_lem_list *head)
{
	t_lem_hash	**table;

	table = create_hash(head);
}

/*
** lemin is the loop to read all the input and to call the function that is
** going to check the input. after the loop is done it checks if it found
** 1 starting and 1 ending room for the ants.
** vl is a struct where i save the data that i read from the file.
** bh is going to be the first link list to save the rooms before i hash them.
*/

void	lemin(void)
{
	t_lem_list	*head;
	char		*line;
	t_data		vl;
	int			fd;

	head = NULL;
	fd = open("input", O_RDONLY);
	ft_bzero(&vl, sizeof(t_data));
	while(get_next_line(fd, &line))
	{
		check_input(line, &vl, &head);
		free(line);
	}
	free(line);
	if (vl.start != 1 || vl.end != 1)
	{
		ft_printf("Error: Either end or start room is missing.\n");
		exit(1);
	}
	lemin_after_retrieving_input(head);
}


int main(void)
{
	lemin();
	return(0);
}