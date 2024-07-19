/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:35:53 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/19 14:16:17 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ARG=(`ruby -e 'print (1..100).to_a.shuffle * " "'`); echo $ARG; ./push_swap $ARG | wc -l

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_array(argc, argv, &a, &b);
	if (argc <= 4)
		sort_three(&a);
	else
		sort_big(&a, &b);
}

void	init_array(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	i;

	i = 1;
	a->max = ft_atoi(argv[1]);
	a->min = ft_atoi(argv[1]);
	while (i < argc)
	{
		a->stack[i - 1] = ft_atoi(argv[i]);
		if (a->max < a->stack[i - 1])
			a->max = a->stack[i - 1];
		if (a->min > a->stack[i - 1])
			a->min = a->stack[i - 1];
		i++;
	}
	a->size = i - 1;
	b->size = 0;
	b->max = INT_MIN;
	b->min = INT_MAX;
}

bool	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (false);
		i++;
	}
	return (true);
}
