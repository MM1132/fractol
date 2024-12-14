/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:52:44 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/16 09:44:20 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Dogukaan
// If they give you an empty list, you must set it as the first element
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

// t_list	*create_item(void *content, t_list *next)
// {
// 	t_list	*new_item;

// 	new_item = ft_lstnew(content);
// 	if (new_item != NULL)
// 		new_item->next = next;
// 	return (new_item);
// }

// #include <stdio.h>

// void	print_list_content(t_list *list)
// {
// 	printf("Content: %s\n", (char *)(list)->content);
// 	if ((list)->next != NULL)
// 		print_list_content((list)->next);
// }

// int	main(void)
// {
// 	t_list	*item_1 = create_item("item 1 content", NULL);
// 	t_list	*item_2 = create_item("item 2 content", item_1);
// 	t_list	*item_3 = create_item("item 3 content", item_2);
// 	t_list	*item_4 = create_item("item 4 content", item_3);

// 	t_list	**list_of_lists = (t_list **)malloc(sizeof(t_list *) * 4);
// 	if (list_of_lists == NULL)
// 		return (1);
// 	list_of_lists[0] = item_1;
// 	list_of_lists[1] = item_2;
// 	list_of_lists[2] = item_3;
// 	list_of_lists[3] = item_4;

// 	ft_lstadd_back(list_of_lists, create_item("added item's content", NULL));
// 	ft_lstadd_back(list_of_lists, create_item("another addition", NULL));

// 	print_list_content(item_4);

// 	return (0);
// }
