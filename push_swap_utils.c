/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:54:23 by apashkov          #+#    #+#             */
/*   Updated: 2023/10/27 12:15:49 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* t_list	*ft_lstnew(int *input)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->input = input;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
 */
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

/* t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		if (!temp->next)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	temp->next->next = NULL;
}

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!del)
		return;
	if (lst)
	{
		(*del)(lst->input);
		free(lst);
	}
}

void ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*temp;

	temp = *lst;
	if (!del || !lst || !*lst)
		return;
	while (*lst && lst)
	{
		temp = *lst->next;
		(*del)(**lst);
		free(*lst);
		free(lst);
		*lst = temp;
	}
} */