/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:22:27 by moel-gha          #+#    #+#             */
/*   Updated: 2024/02/26 09:22:36 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_pushnew(int content)
{
	t_push	*new;

	new = (t_push *)malloc(sizeof(t_push));
	if (!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

void	ft_pushadd_back(t_push **lst, t_push *new)
{
	t_push	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = *lst;
		while (last->next)
		{
			last = last->next;
		}
		last->next = new;
	}
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

int	stack_size(t_push *head)
{
	int	i;

	if (!head)
		return (0);
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	display_stack(t_push *stack)
{
	t_push	*current;

	current = stack;
	while (current != NULL)
	{
		ft_putnbr(current->data);
		write(1, "\n", 1);
		current = current->next;
	}
}
