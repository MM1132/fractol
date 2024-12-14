/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:13:50 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	second_index;

	index = 0;
	while (dst[index] != 0 && index < dstsize)
		index++;
	if (index == dstsize)
		return (index + ft_strlen(src));
	second_index = 0;
	while (src[second_index] != 0 && index + second_index < dstsize - 1)
	{
		dst[index + second_index] = src[second_index];
		second_index++;
	}
	dst[index + second_index] = 0;
	return (index + ft_strlen(src));
}
