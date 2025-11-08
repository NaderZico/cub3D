/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:53:15 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/25 13:01:11 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char) c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (unsigned char)c)
	{
		return ((char *)s);
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *p = ft_strchr("abcdefg", 'c');
// 	printf("%s", p);
// }