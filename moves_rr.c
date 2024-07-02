/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:16:23 by nleoni            #+#    #+#             */
/*   Updated: 2024/07/01 23:08:26 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list *list)
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
}

void	do_rra(t_list *list, t_final *final)
{
	rr(list);
	final->moves++;
	write(1, "rra\n", 4);
}

void	do_rrb(t_list *stack_b, t_final *final)
{
	rr(stack_b);
	final->moves++;
	write(1, "rrb\n", 4);
}

void	do_rrr(t_list *list, t_list *stack_b, t_final *final)
{
	rr(list);
	rr(stack_b);
	final->moves++;
	write(1, "rrr\n", 4);
}
