/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 11:41:41 by vmulder        #+#    #+#                */
/*   Updated: 2019/07/12 11:45:01 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnlen(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
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
	while (*psource != '\0' && *psource != c)
	{
		*pdes = *psource;
		pdes++;
		psource++;
	}
	*pdes = '\0';
	return (res);
}