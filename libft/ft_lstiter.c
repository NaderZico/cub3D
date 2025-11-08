/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:46:03 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/29 15:21:10 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void print_content(void *content)
// {
// 	printf("%s\n", (char *)content);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*second;
// 	t_list	*third;
// 	t_list	*fourth;

// 	head = ft_lstnew("First Node");
// 	second = ft_lstnew("Second Node");
// 	third = ft_lstnew("Third Node");
// 	fourth = ft_lstnew("Fourth Node");
// 	head->next = second;
// 	second->next = third;
// 	third->next = fourth;

// 	ft_lstiter(head, print_content);
// }
