/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:05:59 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/14 19:42:00 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	non_numeric_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9')))
			return (1);
		if ((str[i] == '-' || str[i] == '+') && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

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

static int	duplicates(t_list *stack, int input)
{
	int i;
	i = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->input == input)
		{
			if (input == 0)
				i++;
			else
				return (1);
			if (i == 2)
				return (1);
		}
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
        printf("%d\n", current->input);
        current = current->next;
    }
}

int	fill_stack_a(t_list *a_stack, char **argv, int argc)
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
		if (non_numeric_error(argv[i]) == 1 || duplicates(temp, ft_atoi(argv[i])) == 1)
			//free_array(argv);
			return (write(2, "Error\n", 6), free_a_stack(&a_stack), 1);
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
	return (0);
}

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
		return (free_array(argv), 0);
	if (fill_stack_a(a_stack, argv, argc) == 1 || errors(argv, &a_stack) == 1)
		return (0);
	set_indexes(&a_stack);
	if (ft_lstsize(a_stack) == 3)
		three_sort(&a_stack);
	else if (ft_lstsize(a_stack) == 4)
		four_sort(&a_stack, &b_stack);
	else if (ft_lstsize(a_stack) == 5)
		five_sort(&a_stack, &b_stack);
	else
		radix_sort(&a_stack, &b_stack);

	printf("Stack A:\n");
	print_list(a_stack);
	printf("Stack B:\n");
	print_list(b_stack);
	free_a_stack(&a_stack);
}