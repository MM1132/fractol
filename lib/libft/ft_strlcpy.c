/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:43:30 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	index;

	src_len = 0;
	while (src[src_len] != 0)
		src_len++;
	if (dstsize == 0)
		return (src_len);
	index = 0;
	while (src[index] != 0 && index < dstsize - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = 0;
	return (src_len);
}
