/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:35:53 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/19 17:36:56 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//ARG=(`ruby -e 'print (1..100).to_a.shuffle * " "'`); echo $ARG; ./push_swap $ARG | wc -l

char	**all_free(char **result, int index)
{
	while (index--)
		free(result[index]);
	free(result);
	return (0);
}

bool	is_digit_str(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	word_count(char **words)
{
	int	count;

	count = 0;
	while (*words)
	{
		count++;
		words++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_array(argc, argv, &a, &b);
	if (is_sorted(&a))
		return (0);
	if (a.size < 4)
		sort_three(&a);
	else
		sort_big(&a, &b);
}

void	init_array(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	i;
	int j;
	int index;
	char **nbs;

	a->size = 0;
	a->max = INT_MIN;
	a->min = INT_MAX;
	b->size = 0;
	b->max = INT_MIN;
	b->min = INT_MAX;
	i = 1;
	j = 0;
	while (i < argc)
	{
		index = 0;
		nbs = ft_split(argv[i], ' ');
		if (!nbs)
			exit(1);
		while (nbs[index])
		{
			if (!is_digit_str(nbs[index]))
			{
				ft_putstr_fd("Error\n", 2);
				all_free(nbs, word_count(nbs));
				exit(1);
			}
			a->stack[j] = ft_atoi(nbs[index]);
			if (a->max < a->stack[j])
				a->max = a->stack[j];
			if (a->min > a->stack[j])
				a->min = a->stack[j];
			j++;
			index++;
		}
		all_free(nbs, index);
		i++;
	}
	a->size = j;
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

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }
