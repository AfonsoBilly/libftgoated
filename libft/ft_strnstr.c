/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:15:01 by marvin            #+#    #+#             */
/*   Updated: 2025/10/28 17:15:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    if (!*little)
        return ((char*) big);

    while (i < len && big[i])
    {
        j = 0;
        while (big[i + j] && little[j] && big[i + j] == little[j] && (i + j) < len)
            j++;
        if (little[j] == '\0')
            return ((char *)big + i);
        i++;
    }
    return (NULL);
}