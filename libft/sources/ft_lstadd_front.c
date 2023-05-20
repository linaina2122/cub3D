/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:22:20 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/17 00:22:22 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

// static void	my_prtlist(t_list *head)
// {
// 	t_list	*temp = head;
// 	while(temp != NULL)
// 	{
// 		printf("%s->", temp->content);
// 		temp = temp->next;
// 		printf("next %p\n", temp);
// 	}
// 	printf("NULL");
// }
// int main()
// {
// 	t_list *head;
// 	t_list	lst1, lst2, lst3, new;
// 	new.content = ft_strdup("naldin");
// 	lst1.content = ft_strdup("boro");
// 	lst2.content = ft_strdup("zaman");
// 	lst3.content = ft_strdup("daxiba");
// 	head = &lst1;
// 	lst1.next = &lst2;
// 	lst2.next = &lst3;
// 	lst3.next = NULL;
// 	ft_lstadd_front(&head, &new);
// 	ft_prtlist(head);
// }