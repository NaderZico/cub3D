/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:21:07 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/29 13:05:59 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*second;
// 	t_list	*third;
// 	t_list	*fourth;
// 	int		size;

// 	head = ft_lstnew("First Node");
// 	second = ft_lstnew("Second Node");
// 	third = ft_lstnew("Third Node");
// 	fourth = ft_lstnew("Fourth Node");
// 	head->next = second;
// 	second->next = third;
// 	third->next = fourth;
// 	size = ft_lstsize(head);
// 	printf("List size: %d\n", size);
// 	return (0);
// }
