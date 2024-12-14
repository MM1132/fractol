/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:04:27 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 20:13:53 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Looks for the last occurrance
char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	converted_character;

	converted_character = (char)c;
	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == converted_character)
		{
			return (&((char *)s)[index]);
		}
		index--;
	}
	return (NULL);
}
