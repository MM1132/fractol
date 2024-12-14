/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:18:25 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_str1;
	unsigned char	*p_str2;

	p_str1 = (unsigned char *)s1;
	p_str2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p_str1 != *p_str2)
			return (*p_str1 - *p_str2);
		n--;
		p_str1++;
		p_str2++;
	}
	return (0);
}
