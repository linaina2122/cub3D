/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:00:21 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/20 17:00:22 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = len - 1;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d >= s)
	{
		while (len--)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str[100] = "Learningisfun";
//     char *first, *second;
//     first = str;
//     second = str;
//     printf("Original string :%s\n ", str);
//     // when overlap happens then it just ignore it
//     memcpy(first + 8, first, 10);
//     printf("memcpy overlap : %s\n ", str);
//     // when overlap it start from first position
//     memmove(second + 8, first, 10);
//     printf("memmove overlap : %s\n ", str);
//     return 0;
// }