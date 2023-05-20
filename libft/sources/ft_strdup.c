/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:44:52 by bkamal            #+#    #+#             */
/*   Updated: 2023/04/16 01:55:50 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ndup;
	size_t	i;

	i = 0;
	if (n >= ft_strlen(s1))
		n = ft_strlen(s1);
	ndup = (char *)malloc(sizeof(char) * (n + 1));
	if (!ndup)
		return (NULL);
	while (s1[i] && i < n)
	{
		ndup[i] = s1[i];
		// if (ndup[i] == '\n')
		// 	ndup[i] = ' ';
		i++;
	}
	while (i < n)
		ndup[i++] = ' ';
	ndup[i] = '\0';
	return (ndup);
}

