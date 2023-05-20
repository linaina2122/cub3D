/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:58:33 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/03 17:11:12 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sc;
	unsigned char	*dt;

	if (dst == NULL && src == NULL)
		return (NULL);
	sc = (unsigned char *)src;
	dt = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*dt = *sc;
		dt++;
		sc++;
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	// char src[] = "test basic du memcpy !";
// 	printf("%p\n", memcpy(((void *)0),((void *)0), 3));
// 	printf("%p\n", ft_memcpy(((void *)0),((void *)0), 3));
// 	return 0;
// }