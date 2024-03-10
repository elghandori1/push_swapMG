/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:55:51 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/02 20:55:55 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_args(int ac, char **av, t_push **stack_a)
{
	char	**rslt;

	int (i), (j), (num);
	i = 0;
	while (++i < ac)
	{
		if (!*av[i] || spaces_tabs(av[i]))
			(ft_pushclear(stack_a), ft_error());
		else
		{
			rslt = ft_split(av[i], ' ');
			if (checkparams(rslt))
			{
				j = -1;
				while (rslt[++j])
				{
					num = ft_atoicheck(rslt[j]);
					if (num == INT_MAX || num == INT_MIN)
						(free_split(rslt), ft_error());
					ft_createnode(num, stack_a);
				}
			}
			free_split(rslt);
		}
	}
}

int	main(int ac, char **av)
{
	t_push	*s_a;
	t_push	*s_b;

	s_a = NULL;
	s_b = NULL;
	if (ac < 2)
		return (0);
	initial_args(ac, av, &s_a);
	if (stack_size(s_a) == 2 && (s_a->data > s_a->next->data))
		ft_sa(&s_a);
	else if (stack_size(s_a) == 3)
		sort_three(&s_a);
	else if (stack_size(s_a) == 4)
		sort_four(&s_a, &s_b);
	else if (stack_size(s_a) == 5)
		sort_five(&s_a, &s_b);
	else
	{
		algo_sort(&s_a, &s_b, find_interval(&s_a), stack_size(s_a));
		while (s_b)
			move_max_up(&s_a, &s_b);
	}
	//display_stack(s_a);
	ft_pushclear(&s_a);
	return (0);
}
