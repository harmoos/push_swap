/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:16:23 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/14 21:32:18 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *list, int a)
{
	t_case	*node;
	t_case	*tmp;

	if (list->size < 1)
		return ;
	tmp = list->first;
	while (tmp->next != NULL)
	{
		node = tmp;
		tmp = tmp->next;
	}
	node->next = NULL;
	tmp->next = list->first;
	list->first = tmp;
	if (a)
		write(1, "rra\n", 4);	
}

void	rrb(t_list *stack_b, int a)
{
	t_case	*node;
	t_case	*tmp;

	if (stack_b->size < 1)
		return ;
	tmp = stack_b->first;
	while (tmp->next != NULL)
	{
		node = tmp;
		tmp = tmp->next;
	}
	node->next = NULL;
	tmp->next = stack_b->first;
	stack_b->first = tmp;
	if (a)
		write(1, "rrb\n", 4);	
}

void	rrr(t_list *list, t_list *stack_b, int a)
{
	rra(list, a);
	rrb(stack_b, a);
	write(1, "rrr\n", 4);
}
