/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:17:37 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/24 16:35:47 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void to_uppercase(unsigned int i, char *c)
// {
//     if (*c >= 'a' && *c <= 'z')
//         *c = *c - 32;
// }

// int main()
// {
//     char str[] = "hello";
//     ft_striteri(str, to_uppercase);
//     printf("%s\n", str);
//     return (0);
// }
