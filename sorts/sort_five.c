/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:22:36 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/07 12:22:38 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_to_b(t_push **a, t_push **b)
{
	t_push	*min;

	min = small_elm(a);
	if (min->data == (*a)->next->data)
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
		ft_rra(a);
		ft_pb(a, b);
	}
	else if (min->data == (*a)->next->next->next->next->data)
	{
		ft_rra(a);
		ft_pb(a, b);
	}
}

void	sort_five(t_push **a, t_push **b)
{
	t_push	*min;

	min = small_elm(a);
	if (min->data == (*a)->data)
		ft_pb(a, b);
	else
		min_to_b(a, b);
	sort_four(a, b);
	ft_pa(a, b);
}
