/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:55:02 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/03 09:55:05 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_push **stack_a)
{
	int	temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = (*stack_a)->data;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_a)->next->data = temp;
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_push **stack_b)
{
	int	temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = (*stack_b)->data;
		(*stack_b)->data = (*stack_b)->next->data;
		(*stack_b)->next->data = temp;
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_push **stack_a, t_push **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	write(1, "ss\n", 3);
}
