/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:46:42 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/09 15:46:45 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_to_min(t_push **a)
{
	t_push	*tmp;

	if (!a || !*a)
		return (0);
	tmp = *a;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

int	big_element(t_push **b)
{
	t_push	*current;
	int		biggest;

	current = *b;
	biggest = current->data;
	while (current)
	{
		if (current->data > biggest)
			biggest = current->data;
		current = current->next;
	}
	return (biggest);
}

int	find_index(t_push **b, int max_e)
{
	t_push	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while (tmp)
	{
		if (tmp->data == max_e)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	move_max_up(t_push **a, t_push **b)
{
	int	size;
	int	max_e;

	size = stack_size(*b);
	max_e = 0;
	while (1)
	{
		max_e = find_index(b, big_element(b));
		if (max_e == 0)
			break ;
		else if (max_e <= size / 2)
			ft_rb(b, 0);
		else if (max_e > size / 2)
			ft_rrb(b, 0);
	}
	ft_pa(a, b, 0);
}
