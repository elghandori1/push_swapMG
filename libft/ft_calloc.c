/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:12:41 by moel-gha          #+#    #+#             */
/*   Updated: 2023/11/27 09:23:17 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size > 0 && count >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
