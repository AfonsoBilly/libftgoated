/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:34:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/29 18:34:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  s_len;
    size_t  actual_len;
    size_t  i;
    char    *substr;

    if (!s)
        return (NULL);

    s_len = 0;
    while (s[s_len])
        s_len++;

    if (start >= s_len)
        return (ft_strdup("")); 

    actual_len = s_len - start;
    if (actual_len > len)
        actual_len = len;

    substr = malloc(sizeof(char) * (actual_len + 1));
    if (!substr)
        return (NULL);

    i = 0;
    while (i < actual_len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    
    return (substr);
}
