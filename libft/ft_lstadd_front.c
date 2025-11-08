/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:59 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/29 13:39:26 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
	{
		new->next = *(lst);
		*lst = new;
	}
	else
		*(lst) = new;
}

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*new_node;
// 	t_list	*newer_node;

// 	lst = ft_lstnew(&(char){'c'});
// 	new_node = ft_lstnew(&(char){'b'});
// 	newer_node = ft_lstnew(&(char){'a'});
// 	ft_lstadd_front(&lst, new_node);
// 	ft_lstadd_front(&lst, newer_node);
// 	while (lst)
// 	{
// 		printf("%c -> ", *((char *)lst->content));
// 		lst = lst->next;
// 	}
// 	printf("NULL");
// 	return (0);
// }
