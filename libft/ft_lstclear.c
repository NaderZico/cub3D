/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:41:56 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/29 15:18:24 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}

// void	del_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list *head = ft_lstnew(ft_strdup("First Node"));
// 	t_list *second = ft_lstnew(ft_strdup("Second Node"));
// 	t_list *third = ft_lstnew(ft_strdup("Third Node"));

// 	head->next = second;
// 	second->next = third;

// 	t_list *temp = head;
// 	while (temp)
// 	{
// 		printf("Node content: %s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}

// 	ft_lstclear(&head, del_content);

// 	if (head == NULL)
// 	{
// 		printf("List successfully cleared");
// 	}
// 	else
// 	{
// 		printf("List was not cleared");
// 	}

// 	return (0);
// }
