/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:42:58 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_allocation_size(char const *str, unsigned int start, size_t len)
{
	size_t	max_possible_size;

	max_possible_size = ft_strlen(str) - start + 1;
	if (max_possible_size - 1 > len)
		return (len + 1);
	return (max_possible_size);
}

size_t	get_some_len(size_t len, const char *s, unsigned int start)
{
	if (len > ft_strlen(s))
		return (ft_strlen(s) - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*allocated_string;
	size_t	allocation_size;
	size_t	index;

	allocation_size = get_allocation_size(s, start, len);
	if (start > ft_strlen(s))
	{
		allocated_string = (char *)malloc(sizeof(char));
		if (allocated_string == NULL)
			return (NULL);
		allocated_string[0] = 0;
		return (allocated_string);
	}
	len = get_some_len(len, s, start);
	allocated_string = (char *)malloc(allocation_size * sizeof(char));
	if (allocated_string == NULL)
		return (NULL);
	index = 0;
	while (index < allocation_size - 1)
	{
		allocated_string[index] = s[start + index];
		index++;
	}
	allocated_string[index] = 0;
	return (allocated_string);
}

// TESTS

// #include <stdio.h>

// void	print_test(char const *s, unsigned int start, size_t len)
// {
// 	printf("`%s`, %u, %zu => \n`%s`\n", s, start,
// 			len, ft_substr(s, start, len));
// }

// int	main(void)
// {
// 	char	str[] = "lorem ipsum dolor sit amet";

// 	print_test(str, 0, 10);
// 	print_test(str, 400, 20);
// 	print_test("hola", 0, 18446744073709551615);

// 	return (0);
// }
