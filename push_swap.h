/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:57:14 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/19 12:41:02 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define STACK_SIZE 10000

typedef struct	s_stack
{
	int stack[STACK_SIZE];
	int size;
	int max;
	int min;
}				t_stack;

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "libft/libft.h"

void	swap_ab(t_stack *stack, char *str);
void	swap_ss(t_stack *a, t_stack *b);
void	push_arg1_to_arg2(t_stack *from, t_stack *to, char *str);
void	rotate_ab(t_stack *stack, char *str);
void	rotate_rr(t_stack *a, t_stack *b);
void	reverse_rotate_ab(t_stack *stack, char *str);
void reverse_rotate_rrr(t_stack *a, t_stack *b);


void init_array(int argc, char **argv, t_stack *a, t_stack *b);

bool	is_sorted(t_stack *stack);
void	sort_three(t_stack *array);
void sort_six(t_stack *a, t_stack *b);
void	check_ab(t_stack *a, t_stack *b);
int find_max(t_stack *stack);
int find_min(t_stack *stack);
int find_index(t_stack *stack, int nb);
void updata_minmax(t_stack *from, t_stack *to, int nb);
void sort_big(t_stack *a, t_stack *b);
int find_min_move(t_stack *a, t_stack *b);
int find_near_nb(t_stack *stack, int find);
int min_calculator(t_stack *stack, int nb);
void rotate_stack(t_stack *a, t_stack *b, int a_nb);

void push_a_phase(t_stack *a, t_stack *b);
















# endif