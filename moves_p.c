/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:40:09 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/14 21:20:35 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pa(t_list *list, t_list *stack_b, int a)
{
	t_case	*tmp;	
	
	if (stack_b->size < 1)
		return (0);
	tmp = stack_b->first;
	stack_b->first = stack_b->first->next;
	stack_b->size--;
	tmp->next = list->first;
	list->first = tmp;
	list->size++;
	if (a)
		write(1, "pa\n", 3);
	return (0);
}

int pb(t_list *list, t_list *stack_b, int a)
{
	t_case	*tmp;	
	
	if (list->size < 1)
		return (0);
	tmp = list->first;
	list->first = list->first->next;
	list->size--;tmp->next = stack_b->first;
	stack_b->first = tmp;
	stack_b->size++;
	if (a)
		write(1, "pb\n", 3);
	return (0);
}
