/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:23:49 by apashkov          #+#    #+#             */
/*   Updated: 2023/10/30 10:18:31 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_and_sb(t_list **stack, int opt)
{
	t_list	*swap1;
	t_list	*swap2;
	t_list	*swap3;

	if (ft_lstsize(*stack) < 2)
		return;
	swap1 = *stack;
	swap2 = swap1->next;
	swap3 = swap2->next;
	*stack = swap2;
	swap2->next = swap1;
	swap1->next = swap3;
	if (opt == 'a')
		printf("sa\n");
	else if (opt == 'b')
		printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa_and_sb(stack_a, 'a');
	sa_and_sb(stack_b, 'b');
	printf("ss\n");
}

void	pa_and_pb(t_list **stack_one, t_list **stack_two, int opt)
{
	if (*stack_one == NULL)
		return;
	if (opt == 'a')
		printf("pa\n");
	else if (opt == 'b')
		printf("pb\n");
}
