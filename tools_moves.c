/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:47:45 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/09 15:47:47 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_array(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*sorted_stack_array(t_push **head)
{
	int		i;
	int		*s_arr;
	t_push	*tmp;

	s_arr = malloc(sizeof(int *) * stack_size(*head));
	if (!s_arr)
		return (NULL);
	tmp = *head;
	i = 0;
	while (tmp)
	{
		s_arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	sort_int_array(s_arr, stack_size(*head));
	return (s_arr);
}

void	algo_sort(t_push **a, t_push **b, int interval, int size)
{
	int	i;
	int	*s_arr;

	i = 0;
	s_arr = sorted_stack_array(a);
	while (*a)
	{
		if (interval + i >= size)
			interval = size - i - 1;
		if ((*a)->data <= s_arr[i])
			(ft_pb(a, b, 0), ft_rb(b, 0), i++);
		else if ((*a)->data > s_arr[i] && (*a)->data <= s_arr[i + interval])
		{
			ft_pb(a, b, 0);
			if (stack_size(*b) >= 2 && (*b)->data < (*b)->next->data)
				ft_sb(b, 0);
			i++;
		}
		else if (max_to_min(a) == 0)
			ft_rra(a, 0);
		else
			ft_ra(a, 0);
	}
	free(s_arr);
}
