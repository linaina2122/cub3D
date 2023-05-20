/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:07:13 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/16 23:07:25 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// #include <stdio.h>
// void	ft_prtlist(t_list *head)
// {
// 	t_list	*temp = head;
// 	while(temp != NULL)
// 	{
// 		printf("%s->", temp->content);
// 		temp = temp->next;
// 	}
// 	printf("NULL");
// }
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
// 	ft_prtlist(rass);
// 	printf("STOP RIGHT THERE CRIMINAL SCUM!\n");
// 	printf("%s", pt5.content);
// 	return (0);
// }