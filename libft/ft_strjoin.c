/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:03:58 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/26 12:04:12 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len + 1);
	ft_strlcat(str, s2, len + 1);
	return (str);
}

// #include <stdio.h>
// int main() {
//     char *result;

//     // Test Case 1: Normal string concatenation
//     result = ft_strjoin("Hello, ", "world!");
//     if (result) {
//         printf("Test 1: %s\n", result);  // Expected output: "Hello, world!"
//         free(result);  // Free the allocated memory
//     } else {
//         printf("Test 1: Allocation failed\n");
//     }

//     // Test Case 2: One of the strings is empty
//     result = ft_strjoin("", "world!");
//     if (result) {
//         printf("Test 2: %s\n", result);  // Expected output: "world!"
//         free(result);  // Free the allocated memory
//     } else {
//         printf("Test 2: Allocation failed\n");
//     }

//     // Test Case 3: Both strings are empty
//     result = ft_strjoin("", "");
//     if (result) {
//         printf("Test 3: %s\n", result);  // Expected output: ""
//         free(result);  // Free the allocated memory
//     } else {
//         printf("Test 3: Allocation failed\n");
//     }
// }