/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiogo-f <adiogo-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:00:00 by adiogo-f          #+#    #+#             */
/*   Updated: 2026/04/08 00:00:00 by adiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_nbr(const char *s)
{
	int	i;
	int	digs;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	digs = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		digs++;
		i++;
	}
	return (digs <= 10);
}

static long	parse_long(const char *s)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

static char	**get_tokens(int argc, char **argv, int *ft)
{
	char	**toks;
	int		i;

	*ft = (argc == 2);
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	toks = malloc(sizeof(char *) * argc);
	if (!toks)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		toks[i - 1] = argv[i];
		i++;
	}
	toks[argc - 1] = NULL;
	return (toks);
}

static int	has_dup(int *vals, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (vals[i] == vals[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse_args(int argc, char **argv, int *size)
{
	char	**toks;
	int		*vals;
	int		*ranks;
	int		n;
	int		i;
	int		ft;
	long	v;

	toks = get_tokens(argc, argv, &ft);
	if (!toks)
		error_exit(NULL, 0, NULL);
	n = 0;
	while (toks[n])
		n++;
	if (n == 0)
	{
		free_tokens(toks, ft);
		*size = 0;
		return (NULL);
	}
	vals = malloc(sizeof(int) * n);
	if (!vals)
		error_exit(toks, ft, NULL);
	i = 0;
	while (i < n)
	{
		if (!is_valid_nbr(toks[i]))
			error_exit(toks, ft, vals);
		v = parse_long(toks[i]);
		if (v < INT_MIN || v > INT_MAX)
			error_exit(toks, ft, vals);
		vals[i++] = (int)v;
	}
	if (has_dup(vals, n))
		error_exit(toks, ft, vals);
	ranks = malloc(sizeof(int) * n);
	if (!ranks)
		error_exit(toks, ft, vals);
	compute_ranks(vals, ranks, n);
	free_tokens(toks, ft);
	free(vals);
	*size = n;
	return (ranks);
}
