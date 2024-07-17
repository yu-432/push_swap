/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:58:50 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/17 14:44:32 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ARG=(`ruby -e 'print (1..100).to_a.shuffle * " "'`); echo $ARG; ./push_swap $ARG | wc -l



		// while(a->stack[0] != minNb)
		// {
		// 	if (nb_index < a->size/2)
		// 		rotate_ab(a, "ra\n");
		// 	else
		// 		reverse_rotate_ab(a, "rra\n");
		// }
		

int rotate_stack(t_stack *a, t_stack *b, int a_index, int a_nb)
{
	int b_index;

	// printf("aindex = %d, a_nb = %d\n", a_index, a_nb);
	if (a_nb < b->min)
	{
		b_index = find_index(b, b->min);
		while (b->min != b->stack[b->size-1] && a->stack[0] != a_nb)
		{
			// printf("min 1\n");
			if (b_index < b->size/2 && a_index < a->size/2)
				rotate_rr(a, b);
			else if (b_index >= b->size/2 && a_index >= a->size/2)
				reverse_rotate_rrr(a, b);
			else
				break;
		}
		while (b->min != b->stack[b->size-1])
		{

			if (b_index < b->size/2)
				rotate_ab(b, "rb\n");
			else
				reverse_rotate_ab(b, "rrb\n");
		}
		while(a->stack[0] != a_nb)
		{
			if (a_index < a->size/2)
				rotate_ab(a, "ra\n");
			else
				reverse_rotate_ab(a, "rra\n");
		}
		return b->min;
	}

	if (a_nb > b->max)
	{
			// printf("max-------------------------\n");

		b_index = find_index(b, b->max);
		while (b->max != b->stack[0] && a->stack[0] != a_nb)
		{
			if (b_index < b->size/2 && a_index < a->size/2)
				rotate_rr(a, b);
			else if (b_index >= b->size/2 && a_index >= a->size/2)
				reverse_rotate_rrr(a, b);
			else
				break;
		}
		while (b->max != b->stack[0])
		{
			if (b_index < b->size/2)
				rotate_ab(b, "rb\n");
			else
				reverse_rotate_ab(b, "rrb\n");
		}
		while(a->stack[0] != a_nb)
		{
			if (a_index < a->size/2)
				rotate_ab(a, "ra\n");
			else
				reverse_rotate_ab(a, "rra\n");
		}
		return 1;
	}
	int i = 0;
	while (i < b->size)
	{
		if (b->stack[i%b->size] > a_nb && b->stack[(i + 1)%b->size] < a_nb)//スタックAからプッシュされる数字の正しい挿入位置を求める。求めた後にその位置まで移動する。
		{
			// printf("else-------------------------\n");
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
			while (b->stack[b->size-1] != nb)
			{
				if (b_index < b->size/2)
					rotate_ab(b, "rb\n");
				else
					reverse_rotate_ab(b, "rrb\n");
			}
			while (a->stack[0] != a_nb)
			{
				if (a_index < a->size/2)
					rotate_ab(a, "ra\n");
				else
					reverse_rotate_ab(a, "rra\n");
			}
			return 1;
		}
		i++;
	}
	return -1;
	
}

void push_b_phase(t_stack *a, t_stack *b)
{
	int l_cost_nb_a;
	int nb_index;

	while(1)
	{
		if (a->size < 4)
			break;
		l_cost_nb_a = find_min_move(a, b);
		nb_index = find_index(a, l_cost_nb_a);
		rotate_stack(a, b, nb_index, l_cost_nb_a);
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
