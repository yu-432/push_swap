/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:33:55 by yooshima          #+#    #+#             */
/*   Updated: 2024/07/19 20:02:09 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	long_overflow(int sign, const char *str)
{
	long	temp;
	long	value;

	value = 0;
	while (ft_isdigit(*str))
	{
		temp = value * 10 + *str - '0';
		if ((sign == 1 && !(temp >= value)) || (sign == -1 && !(temp >= value))
			|| temp > INT_MAX || temp < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		value = temp;
		str++;
	}
	return (value);
}

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
	value = long_overflow(sign, str);
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
