/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 08:59:33 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/14 12:28:11 by svoort        ########   odam.nl         */
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
** reading room connection now and will go in the last if.
** when its ready to start reading the room connections we make a hashtable.
*/

static t_lem_hash	*check_input(char *line, t_data *vl, t_lem_hash *table, t_lem_list **head)
{
	int	d;

	d = 0;
	if (line && ft_strlen(line) == 0)
		error_handling(1, 0); // first try but line didnt need free in this one
	if (vl->ants == 0)
		d = check_ants(line, vl);
	if (line[0] != '#')
		check_dash(line, vl);
	if (!vl->checkc && !d)
		check_start_end(line, vl, head);
	if (vl->checkc)
	{
		if (!vl->checkh)
		{
			table = create_hash(*head, vl); // we now create the hash table here otherwise we can not append the edges to the hashtable.
			vl->checkh = 1;
		}
		if (line[0] != '#')
			check_room_connection(line, table, *vl); // send head also into this file so it where it reads the connections it will add them to our ll
	}
	return (table);
}

static t_lem_hash	*read_input(t_data *vl)
{
	int			fd;
	t_lem_list	*head;
	t_lem_hash	*table;
	char		*line;

	head = NULL; // maybe table = NULL needs to be added aswell.
	fd = open("input", O_RDONLY);
	while(get_next_line(fd, &line))
	{
		if (line)
			table = check_input(line, vl, table, &head);
		free(line);
	}
	free(line);
	return (table);
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
	t_data		vl;
	t_lem_hash	*table;

	ft_bzero(&vl, sizeof(t_data));
	table = read_input(&vl);
	if (vl.start != 1 || vl.end != 1)
		error_handling(2, 0);
	print_connections(table, vl.length);
}


int main(void)
{
	lemin();
	return(0);
}