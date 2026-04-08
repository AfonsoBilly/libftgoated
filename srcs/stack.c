/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiogo-f <adiogo-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:00:00 by adiogo-f          #+#    #+#             */
/*   Updated: 2026/04/08 00:00:00 by adiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int capacity)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->arr = malloc(sizeof(int) * capacity);
	if (!s->arr)
	{
		free(s);
		return (NULL);
	}
	s->size = 0;
	return (s);
}

void	stack_free(t_stack *s)
{
	if (!s)
		return ;
	free(s->arr);
	free(s);
}

int	is_sorted(t_stack *a)
{
	int	i;

	if (a->size <= 1)
		return (1);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
