/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiogo-f <adiogo-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:00:00 by adiogo-f          #+#    #+#             */
/*   Updated: 2026/04/08 00:00:00 by adiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tokens(char **toks, int free_strs)
{
	int	i;

	if (!toks)
		return ;
	if (free_strs)
	{
		i = 0;
		while (toks[i])
			free(toks[i++]);
	}
	free(toks);
}

void	error_exit(char **toks, int free_toks, int *vals)
{
	free_tokens(toks, free_toks);
	if (vals)
		free(vals);
	write(2, "Error\n", 6);
	exit(1);
}

void	compute_ranks(int *vals, int *ranks, int n)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < n)
	{
		rank = 0;
		j = 0;
		while (j < n)
		{
			if (vals[j] < vals[i])
				rank++;
			j++;
		}
		ranks[i] = rank;
		i++;
	}
}
