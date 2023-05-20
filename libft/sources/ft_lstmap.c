/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:06:13 by bkamal            #+#    #+#             */
/*   Updated: 2021/11/24 22:06:15 by bkamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	map = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, node);
		lst = lst->next;
	}
	return (map);
}

// void	del(void *ptr)
// {
// 	free(ptr);
// }
// void	*test_fct(void *test_arg)
// {
// 	test_arg += 1;
// 	return (test_arg);
// }
// #include <stdio.h>
// void	test_prlist(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s\n", lst->content);
// 		lst = lst->next;
// 	}
// }
// int main()
// {
// 	t_list	*head;
// 	char	*f;
// 	char *s;
// 	head = NULL;
// 	f = ft_strdup("Halleluiah");
// 	s = ft_strdup("What");
// 	ft_lstadd_front(&head, ft_lstnew(ft_strdup("why are we in hell?!")));
// 	ft_lstadd_front(&head, ft_lstnew(s));
// 	ft_lstadd_front(&head, ft_lstnew(f));
// 	test_prlist(head);
// 	head = ft_lstmap(head, test_fct, del);
// 	test_prlist(head);
// 	return (0);
// }