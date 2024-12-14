/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:38:31 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 20:13:39 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Looks for the first occurrance of a character in a string
char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	converted_character;

	converted_character = (char)c;
	index = 0;
	while (s[index] != 0 || s[index] == converted_character)
	{
		if (s[index] == converted_character)
		{
			return (&((char *)s)[index]);
		}
		index++;
	}
	return (NULL);
}
