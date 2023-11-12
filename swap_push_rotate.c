/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:23:49 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/12 17:08:22 by apashkov         ###   ########.fr       */
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
		write(1,"sa\n", 3);
	else if (opt == 'b')
		write(1,"sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa_and_sb(stack_a, 'c');
	sa_and_sb(stack_b, 'c');
	write(1,"ss\n", 3);
}

void	pa_and_pb(t_list **stack_one, t_list **stack_two, int opt)
{
	t_list	*temp;

	if (*stack_two == NULL)
		return ;
	temp = *stack_two;
	*stack_two = (*stack_two)->next;
	temp->next = NULL;
	ft_lstadd_front(stack_one, temp);
	if (*stack_one == NULL)
		return;
	if (opt == 'a')
		write(1,"pa\n", 3);
	else if (opt == 'b')
		write(1,"pb\n", 3);
}

void	ra_and_rb(t_list **stack, int opt)
{
	t_list	*sec;
	t_list	*temp;

	temp = *stack;
	sec = temp->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->next = NULL;
	*stack = sec;
	if (opt == 'a')
		write(1,"ra\n", 3);
	else if (opt == 'b')
		write(1,"rb\n", 3);
}

void	rr(t_list **a_stack, t_list **b_stack)
{
	ra_and_rb(a_stack, 'c');
	ra_and_rb(b_stack, 'c');
	write(1,"rr\n", 3);
}
