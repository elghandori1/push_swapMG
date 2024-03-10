/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:21:55 by moel-gha          #+#    #+#             */
/*   Updated: 2024/02/26 09:21:59 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <ctype.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct push
{
	int			data;
	int			index;
	struct push	*next;
}				t_push;

int				checkparams(char **params);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
void			free_split(char **rslt);
t_push			*ft_pushnew(int content);
void			ft_pushadd_back(t_push **lst, t_push *new);
void			ft_pushclear(t_push **lst);
int				stack_size(t_push *head);
int				ft_atoip(const char *str);
void			ft_error(void);
int				spaces_tabs(char *str);
int				ft_pushfind(t_push *stack, int num);
t_push			*small_elm(t_push **a);
void			ft_createnode(int num, t_push **stack_a);
int				ft_pushfind(t_push *stack, int num);
void			ft_sa(t_push **stack_a);
void			display_stack(t_push *stack);
void			ft_sb(t_push **stack_b);
void			ft_ss(t_push **stack_a, t_push **stack_b);
void			ft_pa(t_push **stack_a, t_push **stack_b);
void			ft_pb(t_push **stack_a, t_push **stack_b);
void			ft_ra(t_push **stack_a);
void			ft_rb(t_push **stack_b);
void			ft_rr(t_push **stack_a, t_push **stack_b);
void			ft_rra(t_push **stack_a);
void			ft_rrb(t_push **stack_b);
void			ft_rrr(t_push **stack_a, t_push **stack_b);
void			sort_three(t_push **stack_a);
void			sort_four(t_push **a, t_push **b);
void			sort_five(t_push **a, t_push **b);
int				find_interval(t_push **a);
void			sort_int_array(int *tab, int size);
int				*sorted_stack_array(t_push **head);
int				max_to_min(t_push **a);
void			algo_sort(t_push **a, t_push **b, int interval, int size);
int				stack_biggest(t_push **a);
void			move_max_up(t_push **a, t_push **b);
void			ft_putnbr(int nbr);
void			initial_args(int ac, char **av, t_push **stack_a);

#endif
