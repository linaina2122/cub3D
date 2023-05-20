/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:53:10 by bkamal            #+#    #+#             */
/*   Updated: 2023/04/07 23:38:00 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(needle);
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i + j <= len)
	{
		if (haystack[i] == needle[0] && !ft_strncmp(haystack + i, needle, j))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
