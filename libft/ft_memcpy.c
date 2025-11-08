/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:16:20 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/24 17:23:00 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char src[] = "Hello, world!";
// 	char dst[20];

// 	ft_memcpy(dst, src, 13);

// 	dst[13] = '\0';

// 	printf("Source: %s\n", src);
// 	printf("Destination: %s", dst);

// 	return (0);
// }