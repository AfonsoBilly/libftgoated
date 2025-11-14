/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:15:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 20:15:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;
    
    i = 0;

    while (i < size - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }

    if (size > 0)
        dst[i] = '\0';
    
    while (src[i])
        i++;
    
    return (i);
}
