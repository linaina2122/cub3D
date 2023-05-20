/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:59:39 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/03 21:41:14 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	j = 0;
	if (dstsize == 0 || lendst >= dstsize)
		return (dstsize + lensrc);
	while (src[j] != '\0' && j < dstsize - lendst - 1)
	{
		dst[i + lendst] = src[j];
		i++;
		j++;
	}
	dst[i + lendst] = '\0';
	return (lensrc + lendst);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *dest;
// 	size_t size = 15;
// 	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
// 		return (0);
// 	memset(dest, 0, 15);
// 	memset(dest, 'r', 6);
// 	printf("strlcat    : %lu && %s\n", strlcat(dest, "lorem", size), dest);
// 	memset(dest, 0, 15);
// 	memset(dest, 'r', 6);
// 	printf("ft_strlcat : %lu && %s\n", ft_strlcat(dest, "lorem", size), dest);
// 	return (0);
// }