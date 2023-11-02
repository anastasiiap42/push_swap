/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:49:12 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/02 13:44:11 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_list
{
	int				input;
	int				index;
	struct s_list	*next;
}		t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstdelone(t_list *lst, void (*del)(int));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int input);
int		ft_lstsize(t_list *lst);
void	pa_and_pb(t_list **stack_one, t_list **stack_two, int opt);
void	ra_and_rb(t_list **stack, int opt);
void	rr(t_list **a_stack, t_list **b_stack);
void	rra_and_rrb(t_list **stack, int opt);
void	rrr(t_list **a_stack, t_list **b_stack);
void	sa_and_sb(t_list **stack_a, int opt);
void	ss(t_list **stack_a, t_list **stack_b);
int		ft_lstsize(t_list *lst);

#endif
