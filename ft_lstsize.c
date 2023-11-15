/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:46:35 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/15 12:29:04 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		l;

	l = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		l++;
	}
	return (l);
}
