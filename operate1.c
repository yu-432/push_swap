/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:10:26 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/21 18:22:23 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	t_stack *temp;

	temp = data->a_head->next;
	data->a_head->next = data->a_head->next->next;
	data->a_head->next->next = temp;
	
}