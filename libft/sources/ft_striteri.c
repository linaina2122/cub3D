/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:12:00 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/07 18:12:02 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// int	main()
// {
// 	char	*s = "GIVE ME ESSENCE!";
// 	printf("%s\n\n", s);
// 	ft_striteri(s, ft_test);
// 	printf("%s\n", s);
// 	return (0);
// }
// void	ft_test(unsigned int i, char *s)
// {
// 	s[i] = s[i] + 1;
// }