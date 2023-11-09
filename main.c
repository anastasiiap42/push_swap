/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:05:59 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/08 19:57:32 by apashkov         ###   ########.fr       */
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
int	main(int argc, char **argv)
{
	int	i;
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*temp;
	int	len;

	b_stack = NULL;
	i = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	a_stack = (t_list *)malloc(sizeof(t_list));
	if (!a_stack)
		return (0);
	temp = a_stack;
	while (argv[i])
	{
		a_stack->input = ft_atoi(argv[i]);
		if (argv[i + 1])
		{
			a_stack->next = (t_list *)malloc(sizeof(t_list));
			if (a_stack->next == NULL)
				return (0);
			a_stack = a_stack->next;
		}
		i++;
	}
	a_stack->next = NULL;
	a_stack = temp;
	len = ft_lstsize(a_stack);
	/* if (is_sorted(a_stack) == 1)
	{
		if (len == 5)
			write(1, "five_sort", 9);
		else
		{
			while (len-- > 3)
				pa_and_pb(&b_stack, &a_stack, 'b');
		}
		three_sort(&a_stack);
	} */
	/* b_stack = (t_list *)malloc(sizeof(t_list));
	b_stack->input = 7;
	b_stack->next = (t_list *)malloc(sizeof(t_list));
	b_stack->next->input = 8;
	b_stack->next->next = (t_list *)malloc(sizeof(t_list));
	b_stack->next->next->input = 9;
	b_stack->next->next->next = NULL; */

	//sa_and_sb(&a_stack, 'a');
	pa_and_pb(&b_stack, &a_stack, 'b');
	//rr(&a_stack, &b_stack);
	//rrr(&a_stack, &b_stack);

	printf("Stack A:\n");
	print_list(a_stack);
	printf("Stack B:\n");
	print_list(b_stack);
}