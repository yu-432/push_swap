/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:35:53 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/16 15:53:26 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	init_array(argc, argv, &a, &b);
	check_ab(&a, &b);
	if (argc <= 7)
		sort_six(&a, &b);
	else
		sort_big(&a, &b);
}

void init_array(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	i;

	i = 1;
	a->max = ft_atoi(argv[1]);
	a->min = ft_atoi(argv[1]);
	while(i < argc)
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
			// printf("a-max = %d, a-min = %d, b-max = %d, b-min = %d\n", a->max, a->min, b->max, b->min);

}

void	check_ab(t_stack *a, t_stack *b)
{
	printf("-----stack A, size = %d-----\n", a->size);
	for(int i = 0; i < a->size; i++)
		printf("%d ", a->stack[i]);
	printf("\n");
	printf("-----stack B, size = %d-----\n", b->size);
	for(int i = 0; i < b->size; i++)
		printf("%d ", b->stack[i]);
	printf("\n\n");
}
