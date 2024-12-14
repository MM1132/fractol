/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:09:25 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/25 15:21:42 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_list_atoi(char **numbers)
{
	int	*results;
	int	index;

	index = 0;
	while (numbers[index] != NULL)
		index++;
	results = malloc(sizeof(int) * (index + 1));
	if (results == NULL)
		return (NULL);
	index = 0;
	while (numbers[index] != NULL)
	{
		results[index] = ft_atoi(numbers[index]);
		index++;
	}
	results[index] = 0;
	return (results);
}
