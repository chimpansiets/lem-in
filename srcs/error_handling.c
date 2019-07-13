/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/13 14:36:46 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/13 18:55:36 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

void	error_message(int errornr)
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

void	error_handling(int error_nr, int free_nr, ...)
{
	va_list	listpointer;
	char	**tmp0;
	t_edge	**tmp1;

	tmp0 = NULL;
	tmp1 = NULL;
	error_message(error_nr);
	va_start(listpointer, free_nr);
	while (free_nr)
	{
		if (error_nr < 7)
		{
			tmp0 = va_arg(listpointer, char**);
			ft_printf("wrong input line: %s\n", *tmp0);
			free(*tmp0);
		}
		else
		{
			tmp1 = va_arg(listpointer, t_edge**);
			free(*tmp1);
		}
		free_nr--;
	}
	// here we free line for 1, 2, 3, 4, 5, 6 but in normal leak checker doesnt make a difference
	// if we free it or not, lets check with valgrind.
	va_end(listpointer);
	exit(1);
}
