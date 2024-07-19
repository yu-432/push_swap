/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:57:14 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/19 20:04:03 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define STACK_SIZE 10000

typedef struct	s_stack
{
	int *stack;
	int size;
	int max;
	int min;
}				t_stack;

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "libft/libft.h"

//operations
void	swap_ab(t_stack *stack, char *str);
void	swap_ss(t_stack *a, t_stack *b);
void	push_arg1_to_arg2(t_stack *from, t_stack *to, char *str);
void	rotate_ab(t_stack *stack, char *str);
void	rotate_rr(t_stack *a, t_stack *b);
void	reverse_rotate_ab(t_stack *stack, char *str);
void	reverse_rotate_rrr(t_stack *a, t_stack *b);


void read_arg(int argc, char **argv, t_stack *a);

bool	is_sorted(t_stack *stack);
void	sort_three(t_stack *array);
void	check_ab(t_stack *a, t_stack *b);
int find_max(t_stack *stack);
int find_min(t_stack *stack);
int find_index(t_stack *stack, int nb);
void updata_minmax(t_stack *from, t_stack *to, int nb);
void sort_big(t_stack *a, t_stack *b);
int find_lcost_nb(t_stack *a, t_stack *b);
int find_near_nb(t_stack *stack, int find);
int find_pos_b(t_stack *stack_b, int nb);
void rotate_stack(t_stack *a, t_stack *b, int a_nb);
void	set_a_head(t_stack *a, int set_nb);
void	set_b_tail(t_stack *b, int set_nb);
void	set_both_rotate(t_stack *a, t_stack *b, int b_nb, int a_nb);

void push_a_phase(t_stack *a, t_stack *b);
void	push_b_phase(t_stack *a, t_stack *b);
void	set_stack(t_stack *a, t_stack *b, int a_nb);
void	init_stack(t_stack *a, t_stack *b);
int	word_count(char **words);
bool	is_digit_str(char *str);
void	all_free(char **result, int index);
int	ps_atoi(const char *str);
int	add_to_stack(t_stack *a, char *word, int j);























# endif