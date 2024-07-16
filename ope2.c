/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:27:08 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/14 10:45:35 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate stack[head] to stack[tail]
void	rotate_ab(t_stack *stack, char *str)
{
	int temp;
	int i;
	
	temp = stack->stack[0];
	i = 0;
	while(i < stack->size - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[stack->size - 1] = temp;
	if (str != NULL)
		ft_putstr_fd(str, 1);
}

void	rotate_rr(t_stack *a, t_stack *b)
{
	rotate_ab(a, NULL);
	rotate_ab(b, NULL);
	ft_putstr_fd("rr\n", 1);
}

// rrab stack[tail] to stack[head] 
void	reverse_rotate_ab(t_stack *stack, char *str)
{
	int temp;
	int i;

	temp = stack->stack[stack->size - 1];
	i = stack->size;
	while(i)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[0] = temp;
	if (str != NULL)
		ft_putstr_fd(str, 1);
}

void reverse_rotate_rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_ab(a, NULL);
	reverse_rotate_ab(b, NULL);
	ft_putstr_fd("rrr\n", 1);
}
