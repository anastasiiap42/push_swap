/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:05:59 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/13 19:23:16 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->input > stack->next->input)
			return (1);
		stack = stack->next;
	}
	return (0);
}

//Just for testing purposes
void print_list(t_list *head)
{
	t_list *current;

	current = head;
    while (current != NULL)
	{
        printf("%d\n", current->index);
        current = current->next;
    }
}

void	fill_stack_a(t_list *a_stack, char **argv, int argc)
{
	t_list	*temp;
	int		i;

	temp = a_stack;
	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		a_stack->input = ft_atoi(argv[i]);
		if (argv[i + 1])
		{
			a_stack->next = (t_list *)malloc(sizeof(t_list));
			if (a_stack->next == NULL)
				return;
			a_stack = a_stack->next;
		}
		i++;
	}
	a_stack->next = NULL;
	a_stack = temp;
}

/* void	the_algorithm(t_list **a_stack, t_list **b_stack)
{
	if (ft_lstsize(a_stack) == 2)
		sa_and_sb(&a_stack, 'a');
	else if (ft_lstsize(a_stack) == 3)
		three_sort(&a_stack);
	else if (ft_lstsize(a_stack) == 5)
	else
		radix_sort()
} */

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;

	b_stack = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	a_stack = (t_list *)malloc(sizeof(t_list));
	if (!a_stack)
		return (0);
	fill_stack_a(a_stack, argv, argc);
	set_indexes(&a_stack);
	/* if (is_sorted(a_stack) == 1)
	{
		sorting_algorithm(&a_stack, &b_stack);
	} */
	/* b_stack = (t_list *)malloc(sizeof(t_list));
	b_stack->input = 7;
	b_stack->next = (t_list *)malloc(sizeof(t_list));
	b_stack->next->input = 8;
	b_stack->next->next = (t_list *)malloc(sizeof(t_list));
	b_stack->next->next->input = 9;
	b_stack->next->next->next = NULL; */

	//sa_and_sb(&a_stack, 'a');
	//rr(&a_stack, &b_stack);
	//rrr(&a_stack, &b_stack);

	printf("Stack A:\n");
	print_list(a_stack);
	/* printf("Stack B:\n");
	print_list(b_stack);
	free_a_stack(&a_stack); */
}