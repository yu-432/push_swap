/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:24:01 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/19 13:38:13 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (is_sorted(stack))
		return ;
	if (stack->stack[0] < stack->stack[1])
	{
		reverse_rotate_ab(stack, "rra\n");
		if (!is_sorted(stack))
			swap_ab(stack, "sa\n");
	}
	else if (stack->stack[1] < stack->stack[2])
	{
		if (stack->stack[0] < stack->stack[2])
			swap_ab(stack, "sa\n");
		else
			rotate_ab(stack, "ra\n");
	}
	else
	{
		rotate_ab(stack, "ra\n");
		swap_ab(stack, "sa\n");
	}
}
