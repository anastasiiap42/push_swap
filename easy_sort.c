/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:37:03 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/15 16:02:04 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*the_highest(t_list *stack)
{
	int		res;
	t_list	*the_node;

	res = INT_MIN;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->input > res)
		{
			res = stack->input;
			the_node = stack;
		}
		stack = stack->next;
	}
	return (the_node);
}

static t_list	*the_smallest(t_list *stack)
{
	int		res;
	t_list	*the_node;

	res = INT_MAX;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->index < res)
		{
			res = stack->index;
			the_node = stack;
		}
		stack = stack->next;
	}
	return (the_node);
}

void	three_sort(t_list **stack_a)
{
	if (*stack_a == the_highest(*stack_a))
		ra_and_rb(stack_a, 'a');
	else if ((*stack_a)->next == the_highest(*stack_a))
		rra_and_rrb(stack_a, 'a');
	if ((*stack_a)->input > (*stack_a)->next->input)
		sa_and_sb(stack_a, 'a');
}

void	four_sort(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->next == the_smallest(*stack_a))
		ra_and_rb(stack_a, 'a');
	else if (!(*stack_a == the_smallest(*stack_a)))
	{
		while (*stack_a != the_smallest(*stack_a))
			rra_and_rrb(stack_a, 'a');
	}
	pa_and_pb(stack_b, stack_a, 'b');
	three_sort(stack_a);
	pa_and_pb(stack_a, stack_b, 'a');
}

void	five_sort(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->next == the_smallest(*stack_a)
		|| (*stack_a)->next->next == the_smallest(*stack_a))
	{
		while (*stack_a != the_smallest(*stack_a))
			ra_and_rb(stack_a, 'a');
	}
	else if (*stack_a != the_smallest(*stack_a))
	{
		while (*stack_a != the_smallest(*stack_a))
			rra_and_rrb(stack_a, 'a');
	}
	pa_and_pb(stack_b, stack_a, 'b');
	four_sort(stack_a, stack_b);
	pa_and_pb(stack_a, stack_b, 'a');
}
