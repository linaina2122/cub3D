/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:25:23 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/02 14:40:15 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'z' - 'Z');
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
// 	printf("%c\n",  ft_tolower('A'));
// 	printf("%c\n", tolower('A'));
// 	return 0;
// }