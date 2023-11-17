/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:54:23 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/15 15:17:45 by apashkov         ###   ########.fr       */
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
		write(1, "rra\n", 4);
	else if (opt == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a_stack, t_list **b_stack)
{
	rra_and_rrb(a_stack, 'c');
	rra_and_rrb(b_stack, 'c');
	write(1, "rrr\n", 4);
}

void	free_a_stack(t_list **stack)
{
	t_list	*temp;

	if (stack == NULL)
		return ;
	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	free_all(t_list **stack, char **argv, int argc)
{
	if (argc == 2)
		free_array(argv);
	if (!(*stack))
		return ;
	free_a_stack(stack);
}

int	overflow(char **argv)
{
	int			i;
	long int	nb;

	i = 0;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}
