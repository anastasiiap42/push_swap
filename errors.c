/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:37:24 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/14 19:09:14 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errors(char **argv, t_list **a_stack)
{
	int	i;
	long int nb;

	i = 0;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			//free_array(argv);
			return (write(2, "Error\n", 6), free_a_stack(a_stack), 1);
		}
		i++;
	}
	return (0);
}