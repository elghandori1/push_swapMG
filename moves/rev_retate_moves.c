/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_retate_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:54:53 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/03 09:54:55 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_push **stack_a)
{
	t_push	*prev;
	t_push	*current;

	if (*stack_a && (*stack_a)->next)
	{
		prev = NULL;
		current = *stack_a;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		current->next = *stack_a;
		*stack_a = current;
		write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_push **stack_b)
{
	t_push	*prev;
	t_push	*current;

	if (*stack_b && (*stack_b)->next)
	{
		prev = NULL;
		current = *stack_b;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		current->next = *stack_b;
		*stack_b = current;
		write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_push **stack_a, t_push **stack_b)
{
	ft_rra(stack_a);
	ft_rra(stack_b);
	write(1, "rrr\n", 4);
}
