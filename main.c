/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:05:59 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/02 18:34:09 by apashkov         ###   ########.fr       */
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
int	main(int argc, char **argv)
{
	int	i;
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*temp;

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

	/* b_stack = (t_list *)malloc(sizeof(t_list));
	b_stack->input = 7;
	b_stack->next = (t_list *)malloc(sizeof(t_list));
	b_stack->next->input = 8;
	b_stack->next->next = (t_list *)malloc(sizeof(t_list));
	b_stack->next->next->input = 9;
	b_stack->next->next->next = NULL; */

	//sa_and_sb(&a_stack, 'a');
	//pa_and_pb(&b_stack, &a_stack, 'b');
	//rr(&a_stack, &b_stack);
	//rrr(&a_stack, &b_stack);

	printf("Stack A:\n");
	print_list(a_stack);
	printf("Stack B:\n");
	print_list(b_stack);
}