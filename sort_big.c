/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:58:50 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/19 12:22:22 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ARG=(`ruby -e 'print (1..100).to_a.shuffle * " "'`); echo $ARG; ./push_swap $ARG | wc -l

void	set_a_head(t_stack *a, int a_nb_index, int set_nb)
{
	while (a->stack[0] != set_nb)
	{
		if (a_nb_index < a->size / 2)
			rotate_ab(a, "ra\n");
		else
			reverse_rotate_ab(a, "rra\n");
	}
}

void	set_b_tail(t_stack *b, int b_nb_index, int set_nb)
{
	while (set_nb != b->stack[b->size-1])
	{
		if (b_nb_index < b->size/2)
			rotate_ab(b, "rb\n");
		else
			reverse_rotate_ab(b, "rrb\n");
	}
}

int rotate_stack(t_stack *a, t_stack *b, int a_index, int a_nb)
{
	int b_index;

	if (a_nb < b->min)
	{
		b_index = find_index(b, b->min);
		while (b->min != b->stack[b->size-1] && a->stack[0] != a_nb)
		{
			if (b_index < b->size/2 && a_index < a->size/2)
				rotate_rr(a, b);
			else if (b_index >= b->size/2 && a_index >= a->size/2)
				reverse_rotate_rrr(a, b);
			else
				break;
		}
		set_b_tail(b, b_index, b->min);
		set_a_head(a, a_index, a_nb);
		return b->min;
	}

	if (a_nb > b->max)
	{

		b_index = find_index(b, b->min);
		while (b->max != b->stack[0] && a->stack[0] != a_nb)
		{
			if (b_index < b->size/2 && a_index < a->size/2)
				rotate_rr(a, b);
			else if (b_index >= b->size/2 && a_index >= a->size/2)
				reverse_rotate_rrr(a, b);
			else
				break;
		}

		set_b_tail(b, b_index, b->min);
		set_a_head(a, a_index, a_nb);

		return 1;
	}
	int i = 0;
	while (i < b->size)
	{
		if (b->stack[i%b->size] > a_nb && b->stack[(i + 1)%b->size] < a_nb)
		{
			int nb = b->stack[i];
			b_index = find_index(b, nb);
			while (b->stack[b->size-1] != nb && a->stack[0] != a_nb)//移動ループ
			{
				if (b_index < b->size/2 && a_index < a->size/2)
					rotate_rr(a, b);
				else if(b_index >= b->size/2 && a_index >= a->size/2)
					reverse_rotate_rrr(a, b);
				else
					break;
			}
			set_b_tail(b, b_index, nb);
			set_a_head(a, a_index, a_nb);

			return 1;
		}
		i++;
	}
	return -1;
	
}

void push_b_phase(t_stack *a, t_stack *b)
{
	int l_cost_nb_a;
	int anb_index;

	while(1)
	{
		if (a->size < 4)
			break;
		l_cost_nb_a = find_min_move(a, b);
		anb_index = find_index(a, l_cost_nb_a);
		rotate_stack(a, b, anb_index, l_cost_nb_a);
		push_arg1_to_arg2(a, b, "pb\n");
	}
}

void push_a_phase(t_stack *a, t_stack *b)
{
	while(b->size != 0)
	{
		if ((a->stack[0] > b->stack[0] && a->stack[a->size-1] < b->stack[0]) ||
			(b->stack[0] < a->min && a->min == a->stack[0]) ||
			(b->stack[0] > a->max && a->max == a->stack[a->size-1]))
			push_arg1_to_arg2(b, a, "pa\n");
		else
			reverse_rotate_ab(a, "rra\n");
	}
	while(!is_sorted(a))
	{
		if(find_index(a, a->min) < a->size / 2)
			rotate_ab(a, "ra\n");
		else
			reverse_rotate_ab(a, "rra\n");
	}
}

void sort_big(t_stack *a, t_stack *b)
{
	push_arg1_to_arg2(a, b, "pb\n");
	push_arg1_to_arg2(a, b, "pb\n");
	push_b_phase(a, b);
	sort_three(a);
	push_a_phase(a, b);
}
