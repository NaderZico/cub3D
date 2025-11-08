/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:37:52 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/29 15:34:10 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free((void *)lst);
}

// void	del_content(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
//     t_list *node = ft_lstnew(ft_strdup("Single Node"));

//     if (node)
//     {
//         printf("Node content before deletion: %s\n", (char *)node->content);
//     }

//     ft_lstdelone(node, del_content);

//     printf("Node deleted");

//     return 0;
// }