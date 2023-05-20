/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:49:39 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/18 23:49:41 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// #include <stdio.h>
//
// int	main()
// {
// 	t_list	pt1, pt2, pt3, pt4 , pt5;
// 	t_list	*rass;
//
// 	pt1.content = "TESR";
// 	pt2.content = "122221";
// 	pt3.content = "Irreasonable";
// 	pt4.content = "oberon";
// 	pt5.content = "damned fools";
//
// 	rass = &pt1;
// 	pt1.next = &pt2;
// 	pt2.next = &pt3;
// 	pt3.next = &pt4;
// 	pt4.next = &pt5;
// 	pt5.next = ft_lstnew("fuack");
//	
// 	// ft_prtlist(rass);
// 	printf("STOP RIGHT THERE CRIMINAL SCUM!\n");
// 	printf("%d", ft_lstsize(rass));
// 	return (0);
// }