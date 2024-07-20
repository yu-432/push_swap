/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:33:55 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/20 18:27:17 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_atoi(const char *str)
{
	long	value;
	int		sign;

	sign = 1;
	value = 0;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		value = value * 10 + *str - '0';
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && value - 1 > INT_MAX))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		str++;
	}
	return ((int)(value * sign));
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

int	count_word(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				count++;
			j++;
		}
		i++;
		count++;
	}
	return (count);
}

void	all_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	err_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
