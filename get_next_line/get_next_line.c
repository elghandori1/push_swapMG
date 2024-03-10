/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:16:39 by moel-gha          #+#    #+#             */
/*   Updated: 2024/03/10 21:16:46 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

char	*read_line(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	if (!src || src[i] == '\0')
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] && src[i] == '\n')
		i++;
	dst = malloc((i + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, i + 1);
	return (dst);
}

char	*move_last(char *src)
{
	char	*left;
	int		i;
	int		len;

	i = 0;
	if (!src || !src[i])
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	if (!src[i])
		return (NULL);
	len = ((ft_strlen(src) - i) + 1);
	left = malloc(len * sizeof(char));
	if (!left)
		return (NULL);
	else
		ft_strlcpy(left, src + i + 1, len);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*last;
	char		*return_line;
	char		*tmp_all;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	tmp_all = read_all(fd, last);
	return_line = read_line(tmp_all);
	last = move_last(tmp_all);
	free(tmp_all);
	return (return_line);
}
