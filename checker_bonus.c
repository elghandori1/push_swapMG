/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:17:55 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/10 21:17:58 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	sorted(t_push **a)
{
	t_push	*tmp;

	if (!a || !*a)
		return (0);
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (1);
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	apply_operations(t_push **a, t_push **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_sa(a, 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_sb(b, 1);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_ss(a, b, 1);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_pa(a, b, 1);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_pb(a, b, 1);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_ra(a, 1);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rb(b, 1);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr(a, b, 1);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rra(a, 1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrb(b, 1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrr(a, b, 1);
	else
		ft_error();
}

void	start_checking(t_push **a, t_push **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		apply_operations(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_push	*sb_a;
	t_push	*sb_b;

	sb_a = NULL;
	sb_b = NULL;
	if (ac < 2)
		return (0);
	initial_args(ac, av, &sb_a);
	start_checking(&sb_a, &sb_b);
	if (sorted(&sb_a) == 1 && !sb_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_pushclear(&sb_a);
	if (sb_b)
		ft_pushclear(&sb_b);
	return (0);
}
