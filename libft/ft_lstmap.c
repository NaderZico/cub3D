/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:47:52 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/29 15:12:16 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, tmp);
		lst = lst->next;
	}
	return (newlst);
}

// void	*transform_content(void *content)
// {
// 	char	*str;
// 	int		new_len;
// 	char	*new_str;

// 	str = (char *)content;
// 	new_len = ft_strlen(str) + ft_strlen(" - Transformed") + 1;
// 	new_str = malloc(new_len);
// 	if (new_str)
// 	{
// 		ft_strlcpy(new_str, str, ft_strlen(str) + 1);
// 		ft_strlcat(new_str, " - Transformed", new_len);
// 	}
// 	return (new_str);
// }

// void	del_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*second;
// 	t_list	*third;
// 	t_list	*fourth;
// 	t_list	*new_list;
// 	t_list  *tmp;

// 	head = ft_lstnew(ft_strdup("First Node"));
// 	second = ft_lstnew(ft_strdup("Second Node"));
// 	third = ft_lstnew(ft_strdup("Third Node"));
// 	fourth = ft_lstnew(ft_strdup("Fourth Node"));
// 	head->next = second;
// 	second->next = third;
// 	third->next = fourth;
// 	new_list = ft_lstmap(head, transform_content, del_content);
// 	tmp = new_list;
// 	while (tmp)
// 	{
// 		printf("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_lstclear(&head, del_content);
// 	ft_lstclear(&new_list, del_content);
// 	return (0);
// }
