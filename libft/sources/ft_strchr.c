/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:36:19 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/03 14:43:00 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*st;

	st = (char *)s;
	i = 0;
	if (c >= 256)
		c = c - 256;
	while (st[i] != c)
	{	
		if (!st[i])
			return (NULL);
		i++;
	}
	return (&st[i]);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char s[] = "tripouille";
// 	printf("%s\n", ft_strchr(s, 't' + 255));
// 	printf("%s\n", strchr(s, 't' + 255));
// 	return 0;
// }