/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:34:47 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/29 13:47:21 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*new_node;
// 	t_list	*newer_node;

// 	lst = ft_lstnew(&(char){'a'});
// 	new_node = ft_lstnew(&(char){'b'});
// 	newer_node = ft_lstnew(&(char){'c'});
// 	ft_lstadd_back(&lst, new_node);
// 	ft_lstadd_back(&lst, newer_node);
// 	while (lst)
// 	{
// 		printf("%c -> ", *((char *)lst->content));
// 		lst = lst->next;
// 	}
// 	printf("NULL");
// 	return (0);
// }
