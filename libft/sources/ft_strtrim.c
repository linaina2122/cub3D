/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:01:55 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/06 18:01:32 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_inset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	s;
	size_t	k;
	char	*trim;

	trim = NULL;
	if (!set)
		return (NULL);
	if (s1 != NULL)
	{
		k = 0;
		i = 0;
		s = ft_strlen(s1);
		while (my_inset(set, s1[i]) && i < s)
			i++;
		while (my_inset(set, s1[s - 1]) && s > i)
			s--;
		trim = (char *)malloc(sizeof(char) * (s - i + 1));
		if (!trim)
			return (NULL);
		while (i < s)
			trim[k++] = s1[i++];
		trim[k] = '\0';
	}
	return (trim);
}

// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	char *s1 = "  \t \t \n   \n\n\n\t";
// 	char *s2 = "";
// 	char *ret = ft_strtrim(s1, " \n\t");
// 	if (!strcmp(ret, s2))
// 		printf("SUCCESS");
// 	else
// 		printf("FAIL");
// 	return (0);
// }