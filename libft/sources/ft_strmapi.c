/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:03:17 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/07 15:03:19 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	mapi = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mapi)
		return (NULL);
	while (i < ft_strlen(s))
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}

// int main()
// {
// 	char *s = "The night is long, and the path is dark...";
// 	printf("%s\n", ft_strmapi(s, ft_test));
// 	return (0);
// }
// char	ft_test(unsigned int i, char c)
// {
// 	printf("%d %c    new: ", c, c);
// 	i = i - i + 1;
// 	c = c + i;
// 	printf("%d  %c \n", c, c);
// 	return (c);
// }