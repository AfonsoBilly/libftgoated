/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:12:15 by marvin            #+#    #+#             */
/*   Updated: 2025/10/28 21:12:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*cpstr;

	i = 0;
	while (s[i])
		i++;
	cpstr = malloc(sizeof(*cpstr) * (i + 1));
	if (cpstr == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (s[i])
		{
			cpstr[i] = s[i];
			i++;
        }
		cpstr[i] = '\0';
	}
	return (cpstr);
}