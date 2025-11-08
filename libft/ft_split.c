/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:56:29 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/26 12:54:06 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_clear(char **lst, int i)
{
	while (i--)
		free(lst[i]);
	free(lst);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**lst;
	int		i;
	size_t	word_len;

	lst = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word_len = ft_word_len(s, c);
			lst[i] = ft_substr(s, 0, word_len);
			if (!lst[i])
				return (ft_clear(lst, i));
			s += word_len;
			i++;
		}
	}
	lst[i] = NULL;
	return (lst);
}

// void	free_split(char **split)
// {
// 	int	i;

// 	i = 0;
// 	while (split[i])
// 	{
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// }

// int	main(void)
// {
// 	char	str1[] = "Hello World from 42";
// 	char	**result;
// 	char	str2[] = "Hello,,,World,,,42";
// 	char	str3[] = "NoDelimiterHere";
// 	char	str4[] = "";
// 	char	str5[] = ";;;;";
// 	char	str6[] = ",Hello,World,42,";
// 	char	str7[] = "a";
// 	char	str8[] = "Hello\0World";

// 	// Test case 1: Basic input with spaces as delimiter
// 	result = ft_split(str1, ' ');
// 	printf("Test 1: Split by spaces\n");
// 	for (int i = 0; result[i]; i++)
// 		printf("'%s'\n", result[i]);
// 	free_split(result);
// 	// Test case 2: Input with multiple consecutive delimiters
// 	result = ft_split(str2, ',');
// 	printf("\nTest 2: Split by commas with consecutive delimiters\n");
// 	for (int i = 0; result[i]; i++)
// 		printf("'%s'\n", result[i]);
// 	free_split(result);
// 	// Test case 3: String with no delimiter
// 	result = ft_split(str3, ' ');
// 	printf("\nTest 3: No delimiters present\n");
// 	for (int i = 0; result[i]; i++)
// 		printf("'%s'\n", result[i]);
// 	free_split(result);
// 	// Test case 4: Empty string
// 	result = ft_split(str4, ' ');
// 	printf("\nTest 4: Empty string\n");
// 	if (result[0] == NULL)
// 		printf("Empty array returned as expected\n");
// 	free_split(result);
// 	// Test case 5: Only delimiters in the string
// 	result = ft_split(str5, ';');
// 	printf("\nTest 5: String with only delimiters\n");
// 	if (result[0] == NULL)
// 		printf("Empty array returned as expected\n");
// 	free_split(result);
// 	// Test case 6: Delimiter at the beginning and end
// 	result = ft_split(str6, ',');
// 	printf("\nTest 6: Delimiter at the start and end\n");
// 	for (int i = 0; result[i]; i++)
// 		printf("'%s'\n", result[i]);
// 	free_split(result);
// 	// Test case 7: Single character input
// 	result = ft_split(str7, ' ');
// 	printf("\nTest 7: Single character input\n");
// 	for (int i = 0; result[i]; i++)
// 		printf("'%s'\n", result[i]);
// 	free_split(result);
// 	// Test case 8: Input with null character
// 	result = ft_split(str8, ' ');
// 	printf("\nTest 8: Input with null character\n");
// 	for (int i = 0; result[i]; i++)
// 		printf("'%s'\n", result[i]);
// 	free_split(result);
// 	return (0);
// }
