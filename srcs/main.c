/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiogo-f <adiogo-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:00:00 by adiogo-f          #+#    #+#             */
/*   Updated: 2026/04/08 00:00:00 by adiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*ranks;
	int		n;
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc < 2)
		return (0);
	ranks = parse_args(argc, argv, &n);
	if (n == 0)
		return (0);
	a = stack_new(n);
	b = stack_new(n);
	if (!a || !b)
	{
		free(ranks);
		stack_free(a);
		stack_free(b);
		write(2, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (i < n)
	{
		a->arr[i] = ranks[i];
		i++;
	}
	a->size = n;
	free(ranks);
	if (!is_sorted(a))
		radix_sort(a, b);
	stack_free(a);
	stack_free(b);
	return (0);
}
