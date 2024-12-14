/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:24:39 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		index;
	size_t		needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	index = 0;
	while (haystack[index] != 0 && index < len - needle_len + 1)
	{
		if (needle_len > len)
			return (NULL);
		if (ft_strncmp(&(haystack[index]), needle, needle_len) == 0)
		{
			return (&(((char *)haystack)[index]));
		}
		index++;
	}
	return (NULL);
}

// TESTS

// #include <stdio.h>

// void	do_the_test(const char *haystack, const char *needle, size_t len)
// {
// 	printf("haystack: `%s`\n", haystack);
// 	printf("needle: `%s`\n", needle);
// 	printf("len: `%ld`\n", len);
// 	printf("ft: `%s`\n", ft_strnstr(haystack, needle, len));
// 	printf("original: `%s`\n", strnstr(haystack, needle, len));
// 	printf("\n");
// }

// int	main(void)
// {
// 	char haystack[30] = "aaabcabcd";

// 	do_the_test("lorem ipsum dolor sit amet", "dolor", 0);
// 	do_the_test("", "coucou", -1);
// 	do_the_test(haystack, "aaabc", 5);
// 	do_the_test(haystack, "abcd", 9);
// 	do_the_test(haystack, "a", 1);
// 	do_the_test(((void *)0), "fake", 3);

// 	return (0);
// }
