/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:58:50 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/16 18:48:05 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ARG=(`ruby -e 'print (1..100).to_a.shuffle * " "'`); echo $ARG; ./push_swap $ARG | wc -l

int find_b_pos(t_stack *b, int a_nb)
{
	if (a_nb < b->min)
	{
		while (b->min != b->stack[b->size-1])
		{
			if (find_index(b,a_nb) < b->size/2)
				rotate_ab(b, "rb\n");
			else
				reverse_rotate_ab(b, "rrb\n");
		}
		return b->min;
	}
	else if (a_nb > b->max)
	{
		while (b->max != b->stack[0])
		{
			if (find_index(b,a_nb) < b->size/2)
				rotate_ab(b, "rb\n");
			else
				reverse_rotate_ab(b, "rrb\n");
		}
		return b->max;
	}
	
	int i = 0;
	while (i < b->size)
	{
		if (b->stack[i%b->size] > a_nb && b->stack[(i + 1)%b->size] < a_nb)
		{
			// printf("oya %d, ko %d\n", b->stack[i%b->size], b->stack[(i+ 1)%b->size]);
			int nb = b->stack[i];
			while (b->stack[b->size-1] != nb)
			{
				if (find_index(b,nb) < b->size/2)
					rotate_ab(b, "rb\n");
				else
					reverse_rotate_ab(b, "rrb\n");
			}
			return b->stack[i];
		}
		i++;
	}
	return -1;
	
}

void push_b_phase(t_stack *a, t_stack *b)
{
	while(1)
	{
		if (a->size < 4)
			break;
		int minNb = 0;
		minNb = find_min_move(a, b);
		int index = find_index(a, minNb);
		while(a->stack[0] != minNb)
		{
			if (index < a->size/2)
				rotate_ab(a, "ra\n");
			else
				reverse_rotate_ab(a, "rra\n");
		}
		minNb = find_b_pos(b, minNb);
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
	check_ab(a, b);
}
