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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	apply_operations(t_push **a, t_push **b, char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		ft_sa(a, 1);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		ft_sb(b, 1);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		ft_ss(a, b, 1);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		ft_pa(a, b, 1);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		ft_pb(a, b, 1);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		ft_ra(a, 1);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		ft_rb(b, 1);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		ft_rr(a, b, 1);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		ft_rra(a, 1);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		ft_rrb(b, 1);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
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
