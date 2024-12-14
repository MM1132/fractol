/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:00:51 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 15:24:07 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*allocated_memory;

	allocated_memory = malloc(sizeof(struct s_list));
	if (allocated_memory == NULL)
		return (NULL);
	allocated_memory->content = content;
	allocated_memory->next = NULL;
	return (allocated_memory);
}
