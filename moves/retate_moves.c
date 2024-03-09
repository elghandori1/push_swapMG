/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:54:42 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/03 09:54:45 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_push **stack_a)
{
	t_push	*temp;
	t_push	*current;

	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		current = *stack_a;
		while (current->next)
			current = current->next;
		current->next = temp;
		temp->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_push **stack_b)
{
	t_push	*temp;
	t_push	*current;

	if (*stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		current = *stack_b;
		while (current->next)
			current = current->next;
		current->next = temp;
		temp->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_push **stack_a, t_push **stack_b)
{
	ft_ra(stack_a);
	ft_ra(stack_b);
	write(1, "rr\n", 3);
}
