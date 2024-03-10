/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 08:50:11 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/03 08:50:15 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pushfind(t_push *stack, int num)
{
	t_push	*current;

	current = stack;
	while (current != NULL)
	{
		if (current->data == num)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_pushclear(t_push **lst)
{
	t_push	*next;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}

void	ft_createnode(int num, t_push **stack_a)
{
	t_push	*new_node;

	if (ft_pushfind(*stack_a, num))
	{
		ft_pushclear(stack_a);
		ft_error();
	}
	new_node = ft_pushnew(num);
	ft_pushadd_back(stack_a, new_node);
}

int	find_interval(t_push **a)
{
	int	interval;

	interval = 0;
	if (stack_size(*a) >= 6 && stack_size(*a) <= 16)
		interval = 3;
	else if (stack_size(*a) <= 100)
		interval = 13;
	else if (stack_size(*a) <= 500)
		interval = 35;
	else
		interval = 45;
	return (interval);
}
