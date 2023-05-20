/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:59:53 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/06 21:00:02 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	i;

	i = !n;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_pos(char *itoa, int n)
{
	int				i;
	unsigned int	nr;

	nr = n;
	i = int_len(n) - 1;
	itoa[i + 1] = '\0';
	while (i >= 0)
	{
		itoa[i--] = ((nr % 10) + '0');
		nr /= 10;
	}
	return (itoa);
}

static char	*ft_neg(char *itoa, int n)
{
	int				i;
	unsigned int	nr;

	nr = -1 * n;
	i = int_len(n);
	itoa[0] = '-';
	itoa[i + 1] = '\0';
	while (i > 0)
	{
		itoa[i--] = ((nr % 10) + '0');
		nr /= 10;
	}
	return (itoa);
}

char	*ft_itoa(int n)
{
	char	*itoa;

	if (n < 0)
		itoa = (char *)malloc(sizeof(char) * (int_len(n) + 2));
	else
		itoa = (char *)malloc(sizeof(char) * (int_len(n) + 1));
	if (!itoa)
		return (NULL);
	if (n < 0)
		itoa = ft_neg(itoa, n);
	else
		itoa = ft_pos(itoa, n);
	return (itoa);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%s\n",ft_itoa(2147483647));
// 	return (0);
// }