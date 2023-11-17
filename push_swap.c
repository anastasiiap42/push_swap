/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:36:59 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/15 15:43:29 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_list *a_stack)
{
	a_stack->next = NULL;
	a_stack->input = 0;
	a_stack->index = 0;
}

t_list	*find_next(t_list **stack)
{
	t_list	*temp;
	t_list	*the_smallest_next;

	the_smallest_next = NULL;
	temp = *stack;
	while (temp)
	{
		if ((temp->index == 0) && ((the_smallest_next == NULL)
				|| (temp->input < the_smallest_next->input)))
			the_smallest_next = temp;
		temp = temp->next;
	}
	return (the_smallest_next);
}

void	set_indexes(t_list **stack)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = find_next(stack);
	while (temp)
	{
		temp->index = i;
		i++;
		temp = find_next(stack);
	}
}

static void	radix_sort(t_list **a_stack, t_list **b_stack)
{
	int				i;
	t_list			*temp;
	int				s;

	i = 0;
	while (is_sorted(*a_stack) == 1)
	{
		s = ft_lstsize(*a_stack);
		while (s-- > 0 && is_sorted(*a_stack) == 1)
		{
			temp = *a_stack;
			if (((temp->index >> i) & 1) == 1)
				ra_and_rb(a_stack, 'a');
			else
				pa_and_pb(b_stack, a_stack, 'b');
		}
		while (*b_stack)
			pa_and_pb(a_stack, b_stack, 'a');
		i++;
	}
}

void	sort_stack(t_list **a_stack, t_list **b_stack)
{
	if (ft_lstsize(*a_stack) == 3)
		three_sort(a_stack);
	else if (ft_lstsize(*a_stack) == 4)
		four_sort(a_stack, b_stack);
	else if (ft_lstsize(*a_stack) == 5)
		five_sort(a_stack, b_stack);
	else
		radix_sort(a_stack, b_stack);
}
