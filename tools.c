/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 08:50:43 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/03 08:50:48 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_split(char **rslt)
{
	int	i;

	if (!rslt)
		return ;
	i = 0;
	while (rslt[i])
	{
		free(rslt[i]);
		i++;
	}
	free(rslt);
}

int	spaces_tabs(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	checkparams(char **params)
{
	int	i;
	int	j;

	i = 0;
	while (params[i])
	{
		j = 0;
		if ((params[i][j] == '+' || params[i][j] == '-')
			&& (ft_isdigit(params[i][j + 1])))
			j += 1;
		while (params[i][j])
		{
			if (!ft_isdigit(params[i][j]))
			{
				free_split(params);
				ft_error();
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoicheck(const char *str)
{
	int		sign;
	long	rslt;

	sign = 1;
	rslt = 0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		rslt = (rslt * 10 + *str) - '0';
		if (sign == 1 && (rslt > INT_MAX))
			return (INT_MAX);
		else if (sign == -1 && (-rslt < INT_MIN))
			return (INT_MIN);
		str++;
	}
	return (rslt * sign);
}
