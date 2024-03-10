/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:21:34 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/10 21:21:37 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	initial_args(int ac, char **av, t_push **stack_a)
{
	char	**rslt;

	int (i), (j), (num);
	i = 0;
	while (++i < ac)
	{
		if (!*av[i] || spaces_tabs(av[i]))
			ft_error();
		else
		{
			rslt = ft_split(av[i], ' ');
			if (checkparams(rslt))
			{
				j = -1;
				while (rslt[++j])
				{
					num = ft_atoip(rslt[j]);
					if (num == INT_MAX || num == INT_MIN)
						(free_split(rslt), ft_error());
					ft_createnode(num, stack_a);
				}
			}
			free_split(rslt);
		}
	}
}
