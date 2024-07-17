/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:22:54 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/17 13:49:13 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_sorted(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return false;
		i++;
	}
	return true;
}

int find_max(t_stack *stack)
{
	int i;
	int max;

	i = 0;
	max = stack->stack[0];
	while(stack->size > i)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return max;
}

int find_min(t_stack *stack)
{
	int i;
	int min;

	i = 0;
	min = stack->stack[0];
	while(stack->size > i)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return min;
}

int find_index(t_stack *stack, int nb)
{
	int i;

	i = 0;
	while(stack->size > i)
	{
		if(stack->stack[i] == nb)
			return i;
		i++;
	}
	return -1;
}

int find_near_nb(t_stack *stack, int find)
{
	int i;

	i = 0;
	while(i < stack->size - 1)
	{
		if (find == stack->stack[i] || (stack->stack[i] > find && stack->stack[i+1] < find))
			return stack->stack[i];
		i++;
	}
	return -1;
}