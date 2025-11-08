/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:35:38 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/25 12:36:43 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p;

	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char str[] = "Hello, world!";
// 	char c = 'o';
// 	char *result = ft_memchr(str, c, 13);
// 	if (result)
// 	{
// 		printf("Successfully found '%c'", c);
// 	}
// 	else
// 	{
// 		printf("Failed to find '%c'", c);
// 	}
// }