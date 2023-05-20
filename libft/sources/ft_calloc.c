/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:08:19 by bkamal            #+#    #+#             */
/*   Updated: 2023/04/17 13:45:50 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;

	cal = (void *)malloc(size * count);
	if (!cal)
		return (NULL);
	ft_bzero(cal, size * count);
	return (cal);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*real;

	if (!ptr)
	{
		real = malloc(size);
		return (real);
	}
	else if (!size)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		real = malloc(size);
		if (!real)
			return (NULL);
		ft_memcpy(real, ptr, size);
		free(ptr);
	}
	return (real);
}
