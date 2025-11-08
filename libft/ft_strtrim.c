/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:20:40 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/25 16:20:43 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && end >= start)
		end--;
	if (start > end)
		return (ft_strdup(""));
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}

// int main() {
//     // Example 1: Trim 'l'
//     char *result = ft_strtrim("  ll l l Hello World!     l", "   l");
//     printf("Result: '%s'\n", result);  // Expected: "Ho Word"
//     free(result);

//     // Example 2: Trim spaces
//     result = ft_strtrim("   Hello World!   ", " ");
//     printf("Result: '%s'\n", result);  // Expected: "Hello World!"
//     free(result);

//     // Example 3: Completely trimmed string
//     result = ft_strtrim("eeeeee", "e");
//     printf("Result: '%s'\n", result);  // Expected: ""
//     free(result);

//     return (0);
// }
