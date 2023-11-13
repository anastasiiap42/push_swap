/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:36:59 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/13 19:26:20 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_next(t_list **stack)
{
	t_list	*temp;
	t_list	*the_smallest_next;

	the_smallest_next = NULL;
	temp = *stack;
	while (temp)
	{
		if ((temp->index == 0) && ((the_smallest_next == NULL) || (temp->input < the_smallest_next->input)))
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

void	radix_sort(t_list **a_stack, t_list **b_stack)
{
	int	s;

	s = ft_lstsize(*a_stack);
	while (is_sorted == 1)
	{
		while 
	}
}
