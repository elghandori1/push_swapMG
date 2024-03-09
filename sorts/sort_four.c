/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:42:03 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/04 12:42:07 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_push	*small_elm(t_push **a)
{
	t_push	*current;
	t_push	*small_e;

	current = *a;
	small_e = current;
	while (current)
	{
		if (current->data < small_e->data)
			small_e = current;
		current = current->next;
	}
	return (small_e);
}

void	sort_four(t_push **a, t_push **b)
{
	t_push	*min;

	min = small_elm(a);
	if (min->data == (*a)->data)
		ft_pb(a, b);
	else if (min->data == (*a)->next->data)
	{
		ft_sa(a);
		ft_pb(a, b);
	}
	else if (min->data == (*a)->next->next->data)
	{
		ft_ra(a);
		ft_ra(a);
		ft_pb(a, b);
	}
	else if (min->data == (*a)->next->next->next->data)
	{
		ft_rra(a);
		ft_pb(a, b);
	}
	sort_three(a);
	ft_pa(a, b);
}
