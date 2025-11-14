/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:36:05 by marvin            #+#    #+#             */
/*   Updated: 2025/10/29 20:36:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t  len_s1;
    size_t  len_s2;
    size_t  i;
    size_t  j;
    char    *joined;

    // Safety check
    if (!s1 || !s2)
        return (NULL);
    
    // Calculate length of s1
    len_s1 = 0;
    while (s1[len_s1])
        len_s1++;
    
    // Calculate length of s2
    len_s2 = 0;
    while (s2[len_s2])
        len_s2++;
    
    // Allocate memory for both strings + null terminator
    joined = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
    if (!joined)
        return (NULL);
    
    // Copy s1 into joined
    i = 0;
    while (i < len_s1)
    {
        joined[i] = s1[i];
        i++;
    }
    
    // Copy s2 into joined (right after s1)
    j = 0;
    while (j < len_s2)
    {
        joined[i + j] = s2[j];
        j++;
    }
    
    // Add null terminator
    joined[i + j] = '\0';
    
    return (joined);
}