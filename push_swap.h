/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:49:12 by apashkov          #+#    #+#             */
/*   Updated: 2023/10/27 12:12:24 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_list
{
	int				input;
	int				index;
	struct s_list	*next;
}				t_list;

void	sa_and_sb(t_list **stack_a, int opt);
void	ss(t_list **stack_a, t_list **stack_b);
int		ft_lstsize(t_list *lst);

#endif