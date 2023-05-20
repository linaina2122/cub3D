/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:06:57 by bkamal            #+#    #+#             */
/*   Updated: 2023/04/15 22:28:41 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_newline(char *keep)
{
	int	i;

	i = 0;
	if (!keep)
		return (0);
	while (keep[i])
	{
		if (keep[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*cut_line(char *keep, char *next)
{
	int		len;
	int		i;

	i = 0;
	if (!keep)
		return (NULL);
	len = ft_strlen_gnl(keep) + 1;
	next = (char *)malloc(sizeof(char) * (len + 1));
	if (!next)
	{
		free(keep);
		return (NULL);
	}
	while (i < len)
	{
		next[i] = keep[i];
		i++;
	}
	next[i] = '\0';
	if (next[0] == '\0')
	{
		free(keep);
		return (NULL);
	}
	return (next);
}

char	*cut_rest(char	*keep, char *rest, int i, int r)
{
	i = 0;
	r = 0;
	while (keep[i] != '\n' && keep[i])
		i++;
	if (!keep[i])
	{
		free(keep);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(keep) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	while (keep[i])
		rest[r++] = keep[i++];
	rest[r] = '\0';
	free(keep);
	if (rest[0] == '\0')
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*read_file(int fd, char *keep)
{
	char	*buffy;
	int		n_read;

	buffy = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffy)
		return (NULL);
	while (!check_newline(keep))
	{
		n_read = read(fd, buffy, BUFFER_SIZE);
		if (n_read < 1)
			break ;
		buffy[n_read] = '\0';
		keep = ft_strjoin_gnl(keep, buffy);
	}
	free(buffy);
	return (keep);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*next;
	char		*rest;
	int			i;
	int			r;

	i = 0;
	r = 0;
	next = NULL;
	rest = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	keep = read_file(fd, keep);
	next = cut_line(keep, next);
	if (!next)
		return (NULL);
	keep = cut_rest(keep, rest, i, r);
	return (next);
}


//*modified

// int	get_next_line(char *line, int fd)
// {
// 	static char	*keep;
// 	char		*rest;
// 	int			i;
// 	int			r;

// 	i = 0;
// 	r = 0;
// 	line = NULL;
// 	rest = NULL;
// 	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
// 		return (0);
// 	keep = read_file(fd, keep);
// 	line = cut_line(keep, line);
// 	if (!line)
// 		return (0);
// 	keep = cut_rest(keep, rest, i, r);
// 	return (1);
// }