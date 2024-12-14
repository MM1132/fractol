/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:36:48 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// "    aaa   aaaaaaaaa  a a"
int	count_words(char const *s, char c)
{
	int	word_counter;
	int	word_started;

	word_started = 0;
	word_counter = 0;
	while (*s != 0)
	{
		if (*s != c && word_started == 0)
		{
			word_started = 1;
			word_counter++;
		}
		else if (*s == c && word_started == 1)
		{
			word_started = 0;
		}
		s++;
	}
	return (word_counter);
}

char	*get_next_word(char *str, char splitter)
{
	char	*allocated_memory;
	int		allocation_length;
	int		index;
	int		counter;

	while (*str == splitter)
		str++;
	counter = 0;
	while (str[counter] != 0 && str[counter] != splitter)
		counter++;
	allocation_length = counter;
	allocated_memory = (char *)malloc(sizeof(char) * (allocation_length + 1));
	if (allocated_memory == NULL)
		return (NULL);
	index = 0;
	while (str[index] != splitter && str[index] != 0)
	{
		allocated_memory[index] = str[index];
		index++;
	}
	allocated_memory[index] = 0;
	return (allocated_memory);
}

char	*goto_next_word(char *str, char c)
{
	while (*str == c)
		str++;
	while (*str != c && *str != 0)
		str++;
	return (str);
}

char	**populate_output_array(
	char **output_array,
	int word_counter,
	char *str,
	char c
)
{
	int	word_index;
	int	free_index;

	word_index = 0;
	while (word_index < word_counter)
	{
		output_array[word_index] = get_next_word(str, c);
		if (output_array[word_index] == NULL)
		{
			free_index = 0;
			while (free_index < word_index)
				free(output_array[free_index++]);
			free(output_array);
			return (NULL);
		}
		str = goto_next_word(str, c);
		word_index++;
	}
	output_array[word_index] = NULL;
	return (output_array);
}

// 1. Get how many strings to allocate for
// 2. Allocate
// 3. Start allocating for the strings
// 4. If any string has allocation error, loop backwards and free all memory
char	**ft_split(char const *s, char c)
{
	int		word_counter;
	char	**output_array;
	char	*str;

	word_counter = count_words(s, c);
	output_array = malloc(sizeof(char **) * (word_counter + 1));
	if (output_array == NULL)
		return (NULL);
	str = (char *)s;
	output_array = populate_output_array(output_array, word_counter, str, c);
	if (output_array == NULL)
		return (NULL);
	return (output_array);
}

// TESTS

// #include <stdio.h>

// void	print_test(char *s, char c)
// {
// 	char	**split_array = ft_split(s, c);

// 	while (*split_array != NULL)
// 	{
// 		printf("`%s`\n", *split_array);
// 		split_array++;
// 	}
// }

// int	main(void)
// {
// 	// char	str[] = "   this is a string we will split    ";
// 	// print_test(str, ' ');

// 	char	*splitme = strdup("Tripouille");
// 	print_test(splitme, ' ');
// }
