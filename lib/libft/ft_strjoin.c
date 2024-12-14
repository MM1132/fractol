/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:22:13 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*allocated_string;
	size_t	allocation_size;
	char	*allocated_string_start;

	allocation_size = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
	allocated_string = (char *)malloc(allocation_size);
	if (allocated_string == NULL)
		return (NULL);
	allocated_string_start = allocated_string;
	while (*s1 != 0)
	{
		*allocated_string = *s1;
		s1++;
		allocated_string++;
	}
	while (*s2 != 0)
	{
		*allocated_string = *s2;
		s2++;
		allocated_string++;
	}
	*allocated_string = 0;
	return (allocated_string_start);
}
