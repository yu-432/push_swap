/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:35:53 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/19 20:07:56 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//ARG=(`ruby -e 'print (1..100).to_a.shuffle * " "'`);
// echo $ARG; ./push_swap $ARG | wc -l

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a, &b);
	read_arg(argc, argv, &a);
	if (is_sorted(&a))
		return (0);
	if (a.size < 4)
		sort_three(&a);
	else
		sort_big(&a, &b);
}

void	init_stack(t_stack *a, t_stack *b)
{
	a->size = 0;
	a->max = INT_MIN;
	a->min = INT_MAX;
	b->size = 0;
	b->max = INT_MIN;
	b->min = INT_MAX;
}

void	read_arg(int argc, char **argv, t_stack *a)
{
	int		i;
	int		index;
	char	**nbs;

	i = 1;
	while (i < argc)
	{
		index = 0;
		nbs = ft_split(argv[i], ' ');
		if (!nbs)
			exit(1);
		while (nbs[index])
		{
			if (add_to_stack(a, nbs[index], a->size) == -1)
			{
				all_free(nbs, word_count(nbs));
				exit(1);
			}
			index++;
			a->size++;
		}
		all_free(nbs, index);
		i++;
	}
}

int	add_to_stack(t_stack *a, char *word, int j)
{
	if (!is_digit_str(word))
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	a->stack[j] = ps_atoi(word);
	if (a->max < a->stack[j])
		a->max = a->stack[j];
	if (a->min > a->stack[j])
		a->min = a->stack[j];
	return (1);
}

void	all_free(char **result, int index)
{
	while (index--)
		free(result[index]);
	free(result);
	return ;
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }
