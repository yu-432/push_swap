/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:12:06 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/21 18:17:20 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*lst_new(int content)
{
	t_stack *new_node;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

// lst in a or b stack
void lstadd_back(t_stack *lst, t_stack *new)
{
	if (lst == NULL)
		lst = new;
	else
	{
		new->next = lst->next;
		new->prev = lst;
		lst->next = new;
		new->next->prev = new;
	}
}
