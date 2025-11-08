/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:13:58 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/31 11:19:36 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || !f)
		return (0);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = f(i, (char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char ft_alternate_case(unsigned int index, char c)
// {
//     // If the index is even, uppercase the character
//     if (index % 2 == 0)
//     {
//         if (c >= 'a' && c <= 'z')
//             return (c - 32);  // Convert to uppercase
//     }
//     // If the index is odd, lowercase the character
//     else
//     {
//         if (c >= 'A' && c <= 'Z')
//             return (c + 32);  // Convert to lowercase
//     }
//     return (c);  // Return the character unchanged if no modification
// }

// int main(void)
// {
//     char *original = "hello world!";
//     char *result;

//     // Apply ft_strmapi with the custom ft_toupper function
//     result = ft_strmapi(original, (char (*)(unsigned int,
				// char))ft_alternate_case);

//     if (result)
//     {
//         printf("Original: %s\n", original);
//         printf("Modified: %s\n", result);
//         free(result);  // Free the allocated memory
//     }
//     else
//     {
//         printf("Memory allocation failed!\n");
//     }

//     return (0);
// }