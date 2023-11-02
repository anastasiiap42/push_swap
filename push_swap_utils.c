/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:54:23 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/01 19:28:12 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_and_rrb(t_list **stack, int opt)
{
	t_list	*temp;
	t_list	*finish;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->next->next == NULL)
			finish = temp;
		temp = temp->next;
	}
	temp->next = *stack;
	finish->next = NULL;
	*stack = temp;
	if (opt == 'a')
		write(1,"rra\n", 4);
	else if (opt == 'b')
		write(1,"rrb\n", 4);
}

void	rrr(t_list **a_stack, t_list **b_stack)
{
	rra_and_rrb(a_stack, 'c');
	rra_and_rrb(b_stack, 'c');
	write(1,"rrr\n", 4);
}