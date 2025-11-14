/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:16:53 by marvin            #+#    #+#             */
/*   Updated: 2025/10/28 16:16:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *str = (const unsigned char *)s;
    unsigned char target = (unsigned char)c;

    size_t i;

    i = 0;
    while (i < n)
    {
        if (str[i] == target)
        {
            return ((void *)(str + i));


        }
        i++;
    }
    return (NULL);
}
