/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:31:35 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/28 15:26:25 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_str(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		if (ft_isdigit((int)(str[index])) || \
			str[index] == '-' || str[index] == '+')
		{
			index++;
			continue ;
		}
		return (0);
	}
	return (1);
}
