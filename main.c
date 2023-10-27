/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:05:59 by apashkov          #+#    #+#             */
/*   Updated: 2023/10/27 12:57:50 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list *head)
{
	t_list *current;

	current = head;
    while (current != NULL)
	{
        printf("%d\n", current->input);
        current = current->next;
    }
}
int	main()
{
	t_list	*a_stack = NULL;

	a_stack = (t_list *)malloc(sizeof(t_list));
	a_stack->input = 1;
	a_stack->next = (t_list *)malloc(sizeof(t_list));
	a_stack->next->input = 5;
	a_stack->next->next = (t_list *)malloc(sizeof(t_list));
	a_stack->next->next->input = 3;
	a_stack->next->next->next = NULL;

	sa_and_sb(&a_stack, 'a');

	t_list	*b_stack = NULL;
	printf("Stack A:\n");
	print_list(a_stack);
	printf("Stack B:\n");
	print_list(b_stack);
}