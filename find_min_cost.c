/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:08:41 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/19 13:17:51 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//a[i]が入るスタックBのい位置までの移動回数を求める。
//インデックスのの値を移動回数に加えて合計の移動回数を求める
//インデックス=移動量
//pushしたいa[i]をリターンする
int	find_min_move(t_stack *a, t_stack *b)
{
	int	i;
	int	cost;
	int	min_cost;
	int	nb;

	i = 0;
	min_cost = INT_MAX;
	while (i < a->size - 1)
	{
		cost = min_calculator(b, a->stack[i]);
		if (i > a->size / 2)
			cost += a->size - i;
		else
			cost += i;
		if (min_cost > cost)
		{
			min_cost = cost;
			nb = a->stack[i];
		}
		i++;
	}
	return (nb);
}

//スタック内の正しい位置に移動するまでの回数を求める
//rb, rrbの回数になる
//値の存在する場所が半分を越す場合一番後ろの要素からの距離
int	min_calculator(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i % stack->size] > nb
			&& stack->stack[(i + 1) % stack->size] < nb)
		{
			if (i > stack->size / 2)
				return (stack->size - i);
			else
				return (i);
		}
		i++;
	}
	return (-1); //???????????
}


