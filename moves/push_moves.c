/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:53:56 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/03 09:54:01 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_push **stack_a, t_push **stack_b)
{
	t_push	*temp;

	if (stack_b && *stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
		write(1, "pa\n", 3);
	}
	return ;
}

void	ft_pb(t_push **stack_a, t_push **stack_b)
{
	t_push	*temp;

	if (stack_a && *stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
		write(1, "pb\n", 3);
	}
	return ;
}
