/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:29:04 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/21 18:21:05 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_list(int argc, char **argv, t_data *data)
{
	t_stack	*new;
	int	i;

	i = 1;
	data->a_head = lst_new(atoi(argv[i]));
	data->list_last_a = data->a_head;
	i++;
	while(i < argc)
	{
		new = lst_new(atoi(argv[i]));
		if (!new)
			exit(1) ;
		lstadd_back(data->list_last_a, new);
		data->list_last_a = new;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data data;

	// init list a
	init_list(argc, argv, &data);
	
	printf("stack a %p\n", data.a_head);
	data.list_last_a = data.a_head;
	while(1)
	{
		printf("%d\n", data.list_last_a->content);
		if(data.list_last_a->next != data.a_head)
			data.list_last_a = data.list_last_a->next;
		else
			break ;
	}


	
	swap_a(&data);



	//check list 
	printf("stack a %p\n", data.a_head);
	data.list_last_a = data.a_head;
	while(1)
	{
		printf("%d\n", data.list_last_a->content);
		if(data.list_last_a->next != data.a_head)
			data.list_last_a = data.list_last_a->next;
		else
			break ;
	}

	// printf("stack b %p\n", data.b);
	// data.list_last_b = data.b;
	// while(1)
	// {
	// 	if(data.list_last_b->next != data.b)
	// 		data.list_last_b = data.list_last_b->next;
	// 	else
	// 		break;
	// 	printf("%d\n", data.list_last_b->content);
	// }
	(void)argc;
	(void)argv;

}