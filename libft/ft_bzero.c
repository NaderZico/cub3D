/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:23:12 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/24 17:08:05 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*p = 0;
		p++;
		i++;
	}
}

// int	main(void)
// {
// 	char s[6] = "abcde";
// 	ft_bzero(s, 3);
// 	// printf("%s", s);
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("s[%d] = %d\n", i, s[i]);
// 	}
// }