/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:10:34 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/15 12:31:56 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->input);
		free(lst);
	}
}
