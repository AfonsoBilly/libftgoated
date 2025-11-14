/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:44:05 by marvin            #+#    #+#             */
/*   Updated: 2025/10/30 19:44:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);  
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	i;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	
	end = 0;
	while (s1[end])
		end++;
	if (end > 0)
		end--;
	while (end > start && is_in_set(s1[end], set))
		end--;
	
	len = end - start + 1;

	trimmed = malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (NULL);

	i = 0;
	while (i < len)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[i] = '\0';
	
	return (trimmed);
}