/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:39:46 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_in_pool(char *characters, char c)
{
	while (*characters != 0)
	{
		if (*characters == c)
		{
			return (1);
		}
		characters++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;
	size_t	str_len;

	str_len = ft_strlen(s1);
	start_index = 0;
	while (start_index < str_len && char_in_pool((char *)set, s1[start_index]))
		start_index++;
	end_index = str_len;
	while (end_index > start_index && \
		char_in_pool((char *)set, s1[end_index - 1]))
		end_index--;
	return (ft_substr(s1, start_index, end_index - start_index));
}

// TESTS

// #include <stdio.h>

// void	print_test(char const *s1, char const *set)
// {
// 	printf("%s\n\n", ft_strtrim(s1, set));
// }

// int	main(void)
// {
// 	char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
// 	print_test(s1, " "); // "lorem \n ipsum \t dolor \n sit \t amet"
// 	print_test(s1, "te"); // "lorem ipsum dolor sit am"

// 	return (0);
// }
