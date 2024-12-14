/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:18:28 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_string;
	size_t	string_length;
	size_t	index;

	string_length = ft_strlen(s1);
	new_string = malloc((string_length + 1) * (sizeof(char)));
	if (new_string == NULL)
		return (NULL);
	index = 0;
	while (index < string_length)
	{
		new_string[index] = s1[index];
		index++;
	}
	new_string[index] = 0;
	return (new_string);
}
