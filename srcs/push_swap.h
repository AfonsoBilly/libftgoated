/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiogo-f <adiogo-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:00:00 by adiogo-f          #+#    #+#             */
/*   Updated: 2026/04/08 00:00:00 by adiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int		*arr;
	int		size;
}	t_stack;

/* parse.c */
int		*parse_args(int argc, char **argv, int *size);

/* utils.c */
void	error_exit(char **toks, int free_toks, int *vals);
void	compute_ranks(int *vals, int *ranks, int n);
void	free_tokens(char **toks, int free_strs);

/* stack.c */
t_stack	*stack_new(int capacity);
void	stack_free(t_stack *s);
int		is_sorted(t_stack *a);

/* ops.c */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* radix.c */
void	radix_sort(t_stack *a, t_stack *b);

#endif
