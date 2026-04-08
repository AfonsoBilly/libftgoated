/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiogo-f <adiogo-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:00:00 by adiogo-f          #+#    #+#             */
/*   Updated: 2026/04/08 00:00:00 by adiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->arr[0];
	s->arr[0] = s->arr[1];
	s->arr[1] = tmp;
}

static void	do_rotate(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size < 2)
		return ;
	tmp = s->arr[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->arr[i] = s->arr[i + 1];
		i++;
	}
	s->arr[s->size - 1] = tmp;
}

static void	do_rrotate(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size < 2)
		return ;
	tmp = s->arr[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	s->arr[0] = tmp;
}

static void	do_push(t_stack *dst, t_stack *src)
{
	int	tmp;
	int	i;

	if (src->size == 0)
		return ;
	tmp = src->arr[0];
	i = 0;
	while (i < src->size - 1)
	{
		src->arr[i] = src->arr[i + 1];
		i++;
	}
	src->size--;
	i = dst->size;
	while (i > 0)
	{
		dst->arr[i] = dst->arr[i - 1];
		i--;
	}
	dst->arr[0] = tmp;
	dst->size++;
}

void	sa(t_stack *a)
{
	swap_top(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap_top(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_top(a);
	swap_top(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	do_push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	do_push(b, a);
	write(1, "pb\n", 3);
}

void	ra(t_stack *a)
{
	do_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	do_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	do_rotate(a);
	do_rotate(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	do_rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	do_rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	do_rrotate(a);
	do_rrotate(b);
	write(1, "rrr\n", 4);
}
