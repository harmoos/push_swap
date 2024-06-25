/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:05:02 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/14 21:18:09 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *list, int a)
{
	t_case	*first;
	t_case	*tmp;
	
	if (list->size < 2)
		return ;
	first = list->first;
	list->first = list->first->next;
	tmp = list->first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
	tmp->next->next = NULL;
	if (a)
		write(1, "ra\n", 3);
}

void	rb(t_list *stack_b, int a)
{
	t_case	*first;
	t_case	*tmp;
	
	if (stack_b->size < 2)
		return ;
	first = stack_b->first;
	stack_b->first = stack_b->first->next;
	tmp = stack_b->first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
	tmp->next->next = NULL;
	if (a)
		write(1, "rb\n", 3);
}

void	rr(t_list *list, t_list *stack_b, int a)
{
	ra(list, a);
	rb(stack_b, a);
	write(1, "rr\n", 3);
}
