/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:41:01 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/04 11:41:04 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_push **stack_a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*stack_a)->data;
	n2 = (*stack_a)->next->data;
	n3 = (*stack_a)->next->next->data;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		ft_sa(stack_a, 0);
	else if (n1 > n2 && n2 > n3)
	{
		ft_sa(stack_a, 0);
		ft_rra(stack_a, 0);
	}
	else if (n1 > n2 && n3 > n2)
		ft_ra(stack_a, 0);
	else if (n1 < n2 && n2 > n3 && n3 > n1)
	{
		ft_sa(stack_a, 0);
		ft_ra(stack_a, 0);
	}
	else if (n1 < n2 && n2 > n3 && n2 > n1)
		ft_rra(stack_a, 0);
}
