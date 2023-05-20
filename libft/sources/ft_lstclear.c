/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:13:58 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/19 01:14:00 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

// void	del(void *ptr)
// {
// 	free(ptr);
// }
// #include <stdio.h>
// static void	my_prtlist(t_list *head)
// {
// 	t_list	*temp = head;
// 	while(temp != NULL)
// 	{
// 		printf("%s->", temp->content);
// 		temp = temp->next;
// 		printf("next %p\n", temp);
// 	}
// }
// int main()
// {
// 	t_list	*head;
// 	t_list	*t1, *t2, *t3;
// 	t1 = malloc(sizeof(t_list));
// 	t2 = malloc(sizeof(t_list));
// 	t3 = malloc(sizeof(t_list));
// 	t1->content = ft_strdup("lorminyean");
// 	t2->content = ft_strdup("vanadhul");
// 	t3->content = ft_strdup("Deryangiin");
// 	head = t1;
// 	t1->next = t2;
// 	t2->next = t3;
// 	t3->next = NULL;
// 	my_prtlist(head);
// 	ft_lstclear(&head, del);
// 	printf("list supposedly cleared\n");
// 	my_prtlist(head);
// }