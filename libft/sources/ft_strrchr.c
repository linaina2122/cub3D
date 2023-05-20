/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:06:21 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/03 21:18:10 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if (c >= 256)
		c -= 256;
	while (i > 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char s[] = "bonjour";
// 	printf("ft_strrchr : %s\n", ft_strrchr(s, 't'));
// 	printf("strrchr : %s\n", strrchr(s, 't'));
// 	return 0;
// }