/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:37:03 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/07 11:35:47 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*the_highest(t_list *stack)
{
	int	res;
	t_list	*the_node;
	
	res = INT_MIN;
	if (stack == NULL)
		return (NULL);
	while (stack->next)
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

t_list	*the_smallest(t_list *stack)
{
	int	res;
	t_list	*the_node;

	res = INT_MAX;
	if (stack == NULL)
		return (NULL);
	while (stack->next)
	{
		if (stack->input < res)
		{
			res = stack->input;
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