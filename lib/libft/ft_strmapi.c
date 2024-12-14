/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:26:36 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_string;
	size_t	index;
	size_t	str_len;

	str_len = ft_strlen(s);
	new_string = (char *)malloc((str_len + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	index = 0;
	while (index < str_len)
	{
		new_string[index] = f(index, s[index]);
		index++;
	}
	new_string[index] = 0;
	return (new_string);
}
