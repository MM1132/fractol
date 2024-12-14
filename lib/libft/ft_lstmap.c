/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:44:50 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/16 11:35:17 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_element;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	else
	{
		content = f(lst->content);
		new_list_element = ft_lstnew(content);
		if (new_list_element == NULL)
		{
			del(content);
			return (NULL);
		}
		if (lst->next != NULL)
		{
			new_list_element->next = ft_lstmap(lst->next, f, del);
			if (new_list_element->next == NULL)
			{
				ft_lstdelone(new_list_element, del);
				return (NULL);
			}
		}
		return (new_list_element);
	}
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