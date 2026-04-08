/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiogo-f <adiogo-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:00:00 by adiogo-f          #+#    #+#             */
/*   Updated: 2026/04/08 00:00:00 by adiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int n)
{
	int	bits;

	bits = 0;
	while (n > 0)
	{
		n >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bits;
	int	bit;
	int	i;
	int	size;

	bits = count_bits(a->size - 1);
	if (bits == 0)
		bits = 1;
	bit = 0;
	while (bit < bits)
	{
		size = a->size;
		i = 0;
		while (i < size)
		{
			if ((a->arr[0] >> bit) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
