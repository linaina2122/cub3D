/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:11:22 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/03 17:50:24 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lent;

	lent = 0;
	while (src[lent])
		lent++;
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (lent);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	size_t		a;
// 	char	a0[9];
// 	char	a1[] = "hey world";
// 	a = ft_strlcpy(a0, a1, 9);
// 	printf("length of source: %zu\n", a);
// 	printf("dest: %s\n", a0);
// }