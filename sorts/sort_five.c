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

void	min_head(t_push **a, t_push **b)
{
	t_push	*min;

	min = small_elm(a);
	if (min->data == (*a)->next->data)
	{
		ft_sa(a, 0);
		ft_pb(a, b, 0);
	}
	else if (min->data == (*a)->next->next->data)
	{
		ft_ra(a, 0);
		ft_ra(a, 0);
		ft_pb(a, b, 0);
	}
	else if (min->data == (*a)->next->next->next->data)
	{
		ft_rra(a, 0);
		ft_rra(a, 0);
		ft_pb(a, b, 0);
	}
	else if (min->data == (*a)->next->next->next->next->data)
	{
		ft_rra(a, 0);
		ft_pb(a, b, 0);
	}
}

void	sort_five(t_push **a, t_push **b)
{
	t_push	*min;

	min = small_elm(a);
	if (min->data == (*a)->data)
		ft_pb(a, b, 0);
	else
		min_head(a, b);
	sort_four(a, b);
	ft_pa(a, b, 0);
}
