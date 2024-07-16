/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:24:01 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/14 16:56:46 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *stack)
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

void sort_six(t_stack *a, t_stack *b)
{
	int min;
	int max;
	
	if (a->size < 4)
		return (sort_three(a));
	while(a->size != 3)
		push_arg1_to_arg2(a, b, "pb\n");
	sort_three(a);
	min = find_min(a);
	max = find_max(a);
	while(!is_sorted(a) || b->size != 0)
	{
		if ((max == a->stack[a->size-1] && max < b->stack[0]) ||
			(min == a->stack[0] && a->stack[0] > b->stack[0]) ||
			(a->stack[0] > b->stack[0] && a->stack[a->size-1] < b->stack[0]))
			{
				if (b->stack[0] > max)
					max = b->stack[0];
				else if (b->stack[0] < min)
					min = b->stack[0];
				push_arg1_to_arg2(b, a, "pa\n");
			}
		else
			rotate_ab(a, "ra\n");
	}
}
