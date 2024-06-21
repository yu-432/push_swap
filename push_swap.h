/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:57:14 by yooshima          #+#    #+#             */
/*   Updated: 2024/06/21 17:56:21 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_data
{
	t_stack	*a_head;
	t_stack *b_head;
	t_stack *list_last_a;
	t_stack *list_last_b;
}				t_data;

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	*lst_new(int content);
void	lstadd_back(t_stack *lst, t_stack *new);
void	swap_a(t_data *data);



# endif