/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:35:53 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/20 18:44:14 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//ARG=(`ruby -e 'print (1..100).to_a.shuffle * " "'`);
// echo $ARG; ./push_swap $ARG | wc -l

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (0);
	init_stack(&a, &b, count_word(argv));
	read_arg(argc, argv, &a);
	if (a.size < 4)
		sort_three(&a);
	else
		sort_big(&a, &b);
	free(a.stack);
	free(b.stack);
	return (0);
}

void	init_stack(t_stack *a, t_stack *b, int size)
{
	a->stack = malloc(size * sizeof(int));
	if (!a->stack)
		err_exit();
	a->size = 0;
	a->max = INT_MIN;
	a->min = INT_MAX;
	b->stack = malloc(size * sizeof(int));
	if (!b->stack)
		err_exit();
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
			err_exit();
		while (nbs[index])
		{
			if (add_to_stack(a, nbs[index]) == -1)
			{
				all_free(nbs);
				err_exit();
			}
			index++;
			a->size++;
		}
		all_free(nbs);
		i++;
	}
}



int	add_to_stack(t_stack *a, char *word)
{
	if (!is_digit_str(word))
		return (-1);
	a->stack[a->size] = ps_atoi(word);
	if (!is_unique(a))
		return (-1);
	if (a->max < a->stack[a->size])
		a->max = a->stack[a->size];
	if (a->min > a->stack[a->size])
		a->min = a->stack[a->size];
	return (0);
}

void	err_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }
