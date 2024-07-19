/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:58:50 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/19 13:47:23 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_a_head(t_stack *a, int set_nb)
{
	int	index;

	index = find_index(a, set_nb);
	while (a->stack[0] != set_nb)
	{
		if (index < a->size / 2)
			rotate_ab(a, "ra\n");
		else
			reverse_rotate_ab(a, "rra\n");
	}
}

void	set_b_tail(t_stack *b, int set_nb)
{
	int	index;

	index = find_index(b, set_nb);
	while (set_nb != b->stack[b->size - 1])
	{
		if (index < b->size / 2)
			rotate_ab(b, "rb\n");
		else
			reverse_rotate_ab(b, "rrb\n");
	}
}

void	both_rotate(t_stack *a, t_stack *b, int b_nb, int a_nb)
{
	int	b_index;
	int	a_index;

	b_index = find_index(b, b_nb);
	a_index = find_index(a, a_nb);
	while (b_nb != b->stack[b->size - 1] && a->stack[0] != a_nb)
	{
		if (b_index < b->size / 2 && a_index < a->size / 2)
			rotate_rr(a, b);
		else if (b_index >= b->size / 2 && a_index >= a->size / 2)
			reverse_rotate_rrr(a, b);
		else
			break ;
	}
}

void	rotate_stack(t_stack *a, t_stack *b, int a_nb)
{
	int	i;
	int	b_nb;

	if (a_nb < b->min || a_nb > b->max)
	{
		both_rotate(a, b, b->min, a_nb);
		set_b_tail(b, b->min);
		set_a_head(a, a_nb);
		return ;
	}
	i = 0;
	while (i < b->size)
	{
		if (b->stack[i] > a_nb && b->stack[(i + 1) % b->size] < a_nb)
		{
			b_nb = b->stack[i];
			both_rotate(a, b, b_nb, a_nb);
			set_b_tail(b, b_nb);
			set_a_head(a, a_nb);
			break ;
		}
		i++;
	}
}

void	push_b_phase(t_stack *a, t_stack *b)
{
	int	l_cost_nb_a;

	while (1)
	{
		if (a->size < 4)
			break ;
		l_cost_nb_a = find_min_move(a, b);
		rotate_stack(a, b, l_cost_nb_a);
		push_arg1_to_arg2(a, b, "pb\n");
	}
}

void	push_a_phase(t_stack *a, t_stack *b)
{
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
	{
		if (find_index(a, a->min) < a->size / 2)
			rotate_ab(a, "ra\n");
		else
			reverse_rotate_ab(a, "rra\n");
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	push_arg1_to_arg2(a, b, "pb\n");
	push_arg1_to_arg2(a, b, "pb\n");
	push_b_phase(a, b);
	sort_three(a);
	push_a_phase(a, b);
}
