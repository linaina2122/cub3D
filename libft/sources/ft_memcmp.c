/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:36:17 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/04 18:36:18 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			i;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*us1 != *us2)
			return (*us1 - *us2);
		i++;
		us1++;
		us2++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char s1[50] = "Visages \0s\0tricken with a thousand murders";
//     char s2[50] = "Visages \0s\0ick with a thousand malediction";
//     printf("%d\n", memcmp(s1, s2, 12));
//     printf("%d\n", ft_memcmp(s1, s2, 12));
//     return (0);
// }