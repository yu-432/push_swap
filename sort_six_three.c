/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:24:01 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/19 13:14:01 by yooshima         ###   ########.fr       */
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

void	sort_six(t_stack *a, t_stack *b)
{
	if (a->size < 4)
		return (sort_three(a));
	while (a->size != 3)
		push_arg1_to_arg2(a, b, "pb\n");
	sort_three(a);
	while (b->size != 0)
	{
		if ((a->stack[0] > b->stack[0] && a->stack[a->size - 1] < b->stack[0])
			|| (b->stack[0] < a->min && a->min == a->stack[0])
			|| (b->stack[0] > a->max && a->max == a->stack[a->size - 1]))
			push_arg1_to_arg2(b, a, "pa\n");
		else
			reverse_rotate_ab(a, "rra\n");
	}
	while (!is_sorted(a))
		rotate_ab(a, "ra\n");
}
