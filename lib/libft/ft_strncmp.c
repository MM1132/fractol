/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:47:47 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 == 0)
			return (0);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

// TESTS

// #include <stdio.h>
// void	single_test_strncmp(char *s1, char *s2, size_t n)
// {
// 	printf("`%s`, `%s`, %ld => %d: %d\n", s1, s2, n, 
// ft_strncmp(s1, s2, n), strncmp(s1, s2, n));
// }

// int	main(void)
// {
//     single_test_strncmp("", "", 0);
//     single_test_strncmp("", "", 1);
//     single_test_strncmp("", "", 2);
//     single_test_strncmp("test", "", 0);
//     single_test_strncmp("test", "", 1);
//     single_test_strncmp("test", "", 2);
//     single_test_strncmp("", "test", 0);
//     single_test_strncmp("", "test", 1);
//     single_test_strncmp("", "test", 2);
//     single_test_strncmp("teste", "teste", 0);
//     single_test_strncmp("teste", "teste", 1);
//     single_test_strncmp("teste", "teste", 5);
//     single_test_strncmp("teste", "teste", 6);
//     single_test_strncmp("teste", "teste", 7);
//     single_test_strncmp("teste", "testex", 6);
//     single_test_strncmp("teste", "test", 10);
//     single_test_strncmp("test", "teste", 10);
//     single_test_strncmp("test\200", "test\0", 6);
// }
