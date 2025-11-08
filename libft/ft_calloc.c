/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:20:13 by nakhalil          #+#    #+#             */
/*   Updated: 2024/12/26 13:15:47 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && size > size * count)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return ((void *)ptr);
}

// Function to print memory block
// void	print_memory(const void *ptr, size_t size)
// {
// 	const unsigned char	*bytes = (const unsigned char *)ptr;

// 	for (size_t i = 0; i < size; i++)
// 	{
// 		printf("%02x ", bytes[i]);
// 	}
// 	printf("\n");
// }

// int	main(void)
// {
// 	void *ptr;

// 	// Test Case 1: Normal allocation
// 	ptr = ft_calloc(5, sizeof(int));
// 	if (ptr)
// 	{
// 		printf("Test 1: Success - Memory allocated and initialized\n");
// 		print_memory(ptr, 5 * sizeof(int)); // Should print all zeros
// 		free(ptr);
// 	}
// 	else
// 	{
// 		printf("Test 1: Failure - Memory allocation failed\n");
// 	}

// 	// Test Case 2: Zero count
// 	ptr = ft_calloc(0, sizeof(int));
// 	if (ptr)
// 	{
// 		printf("Test 2: Success - Memory allocated with zero count\n");
// 		free(ptr);
// 	}
// 	else
// 	{
// 		printf("Test 2: Failure - Memory allocation failed\n");
// 	}

// 	// Test Case 3: Zero size
// 	ptr = ft_calloc(5, 0);
// 	if (ptr)
// 	{
// 		printf("Test 3: Success - Memory allocated with zero size\n");
// 		free(ptr);
// 	}
// 	else
// 	{
// 		printf("Test 3: Failure - Memory allocation failed\n");
// 	}

// 	// Test Case 4: Large allocation (check for overflow handling)
// 	ptr = ft_calloc(SIZE_MAX, 2);
// 	if (ptr == NULL)
// 	{
// 		printf("Test 4: Success - Detected overflow and returned NULL\n");
// 	}
// 	else
// 	{
// 		printf("Test 4: Failure - Did not handle overflow properly\n");
// 		free(ptr);
// 	}

// 	// Test Case 5: Small allocation for char array
// 	ptr = ft_calloc(10, sizeof(char));
// 	if (ptr)
// 	{
// 		printf("Test 5: Success - Memory allocated for char array\n");
// 		print_memory(ptr, 10 * sizeof(char)); // Should print all zeros
// 		free(ptr);
// 	}
// 	else
// 	{
// 		printf("Test 5: Failure - Memory allocation failed\n");
// 	}

// 	// Test Case 6: Very large allocation (system-dependent)
// 	ptr = ft_calloc(1000000, sizeof(int));
// 	if (ptr)
// 	{
// 		printf("Test 6: Success - Large memory allocated\n");
// 		free(ptr);
// 	}
// 	else
// 	{
// 		printf("Test 6: Failure
// - Memory allocation failed (might depend on system limits)\n");
// 	}

// 	return (0);
// }