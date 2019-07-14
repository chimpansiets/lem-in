/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/13 14:36:46 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/14 11:47:31 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

static void	error_message(int errornr)
{
	if (errornr == 1)
		ft_printf("Error: Empty lines in file.\n");
	else if (errornr == 2)
		ft_printf("Error: Either end or start room is missing.\n");
	else if (errornr == 3)
		ft_printf("Error: There is a problem with linking rooms.\n");
	else if (errornr == 4)
		ft_printf("Error: The number of ants is incorrect or missing.\n");
	else if (errornr == 5)
		ft_printf("Error: Empty line after start or end.\n");
	else if (errornr == 6)
		ft_printf("Error: Comment after start or end.\n");
	else if (errornr == 7)
		ft_printf("Error: Nonexistent room.\n");
}

void		error_handling(int error_nr, int free_nr, ...)
{
	va_list	listpointer;
	void	*tmp;

	error_message(error_nr);
	va_start(listpointer, free_nr);
	while (free_nr)
	{
		tmp = va_arg(listpointer, void *);
		free(tmp);
		free_nr--;
	}
	va_end(listpointer);
	exit(1);
}
