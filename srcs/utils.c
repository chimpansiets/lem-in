/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/11 21:50:46 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/11 21:56:42 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem-in.h"

static int	ft_strnlen(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

char		*ft_strndup(const char *s1, char c)
{
	const char	*psource;
	char		*pdes;
	char		*res;

	psource = s1;
	pdes = (char *)malloc(sizeof(char) * (ft_strnlen(s1, c) + 1));
	res = pdes;
	if (pdes == NULL)
		return (NULL);
	while (*psource != '\0' || *psource != c)
	{
		*pdes = *psource;
		pdes++;
		psource++;
	}
	*pdes = '\0';
	return (res);
}
