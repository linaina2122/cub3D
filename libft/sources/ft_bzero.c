/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:43:52 by bkamal            #+#    #+#             */
/*   Updated: 2023/04/17 16:24:02 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*v_char;

	i = 0;
	v_char = (unsigned char *) s;
	while (i < n)
		v_char[i++] = 0;
}

void	ft_bspace(void *s, size_t n)
{
	size_t			i;
	unsigned char	*v_char;

	i = 0;
	v_char = (unsigned char *) s;
	while (i < n)
	{
		if (v_char[i] != '1' || v_char[i] != 'S' || v_char[i] != 'N' || v_char[i] != '0' || v_char[i] != 'Z' || v_char[i] != 'E')
			v_char[i++] = 'X';
	}
}