/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_csp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 11:49:10 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/24 15:38:51 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*long_to_a_string(long long l)
{
	char	*s;
	char	*s1;

	s1 = (char *)malloc(sizeof(char) * 3);
	ft_bzero(s1, 3);
	ft_strcat(s1, "0x");
	s = ft_itoa_base(l, 16, 0);
	s1 = ft_strcat(s1, s);
	free(s);
	return (s1);
}

static char	*precis_str(t_struct *val, char *s)
{
	char	*ns;
	int		i;
	int		j;

	j = 0;
	i = (int)ft_strlen(s);
	ns = (char *)malloc(sizeof(char) * i + 1);
	ft_bzero(ns, i + 1);
	if (val->precis < i && val->precis > 0)
		i = val->precis;
	while (i)
	{
		ns[j] = s[j];
		j++;
		i--;
	}
	return (ns);
}

void		put_width_buf(t_struct *val)
{
	int	i;

	i = val->width;
	while (i)
	{
		if (val->bi == BUFF_FULL)
			ft_clearbuf(val);
		if ((val->flagnull && val->precis < 0))
			val->buf[val->bi] = '0';
		else
			val->buf[val->bi] = ' ';
		i--;
		val->bi++;
	}
}

void		ft_cpy_to_buf(t_struct *val, char *s)
{
	int		i;
	int		j;
	char	*ns;

	ns = precis_str(val, s);
	if (val->fmt[val->i] == 'p')
		free(s);
	if (val->specifier == 'p')
		free(s);
	i = ft_strlen(ns);
	j = 0;
	if (val->bi > val->tmpi && val->bi - i >= 0)
		val->bi -= i;
	while (ns[j])
	{
		if (val->bi + 1 == BUFF_FULL)
			ft_clearbuf(val);
		val->buf[val->bi] = ns[j];
		val->bi++;
		j++;
	}
	free(ns);
}

void		ft_cpy_to_buf_lft(t_struct *val, char *s)
{
	int		j;
	char	*ns;

	j = 0;
	ns = precis_str(val, s);
	if (val->fmt[val->i] == 'p')
		free(s);
	val->bi = val->tmpi;
	while (ns[j])
	{
		if (val->bi + 1 == BUFF_FULL)
			ft_clearbuf(val);
		val->buf[val->bi] = ns[j];
		val->bi++;
		j++;
	}
	val->bi = val->width + val->tmpi;
	free(ns);
}
