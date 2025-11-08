/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:24:36 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/29 15:21:00 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

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

// 	printf("%s", (char *)ft_lstlast(head)->content);
// }