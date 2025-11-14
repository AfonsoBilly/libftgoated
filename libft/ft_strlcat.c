/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 03:07:44 by marvin            #+#    #+#             */
/*   Updated: 2025/10/23 03:07:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t dst_len;
    size_t src_len;
    size_t i;

    dst_len = 0;
    while (dst[dst_len] != '\0')
        dst_len++;

    src_len = 0;
    while (src[src_len] != '\0')
        src_len++;

    if (dst_len >= size)
        return (size + src_len);

    i = 0;
    while (dst_len + i < size - 1 && src[i] != '\0')
    {
        dst[dst_len + i] = src[i];
        i++;
    }

    dst[dst_len + i] = '\0';

    return (dst_len + src_len);
}
