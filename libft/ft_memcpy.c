/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:51:22 by marvin            #+#    #+#             */
/*   Updated: 2025/10/21 16:51:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    while (n--) 
    {
    *d++ = *s++;
    }
    return (dest);
}
/*Test main
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("=== Testing memcpy ===\n\n");
    
    // Test 1: String copy
    char src1[] = "Hello, 42!";
    char dest1[50];
    memcpy(dest1, src1, strlen(src1) + 1);
    printf("Test 1 - String:\n");
    printf("  Source: %s\n", src1);
    printf("  Dest:   %s\n\n", dest1);
    
    // Test 2: Integer array
    int src2[] = {1, 2, 3, 4, 5};
    int dest2[5];
    memcpy(dest2, src2, sizeof(src2));
    printf("Test 2 - Int array:\n");
    printf("  Source: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", src2[i]);
    printf("\n  Dest:   ");
    for (int i = 0; i < 5; i++)
        printf("%d ", dest2[i]);
    printf("\n\n");
    
    // Test 3: Partial copy
    char src3[] = "ABCDEFGHIJ";
    char dest3[20] = "xxxxxxxxxx";
    memcpy(dest3, src3, 5);
    dest3[5] = '\0';
    printf("Test 3 - Partial copy (5 bytes):\n");
    printf("  Source: %s\n", src3);
    printf("  Dest:   %s\n\n", dest3);
    
    // Test 4: Zero bytes
    char dest4[10] = "unchanged";
    memcpy(dest4, "test", 0);
    printf("Test 4 - Zero bytes:\n");
    printf("  Dest:   %s (should be unchanged)\n\n", dest4);
    
    printf("All tests completed!\n");
    return 0;
} */