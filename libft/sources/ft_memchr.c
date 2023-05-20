/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:12:59 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/04 18:13:00 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*us;
	size_t			i;	

	i = 0;
	uc = (unsigned char)c;
	us = (unsigned char *)s;
	if (!c && !n)
		return (NULL);
	while (us[i] != uc && i + 1 < n)
		i++;
	if (us[i] == uc)
		return ((void *)&us[i]);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char s[] = {0, 1, 2 ,3 ,4 ,5};
//     printf("%s\n", ft_memchr(s, 0, 1));
//     printf("%s\n", s);
//     printf("%s\n", memchr(s, 0, 1));
//     return (0);
// }