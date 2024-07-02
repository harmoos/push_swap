/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:05:02 by nleoni            #+#    #+#             */
/*   Updated: 2024/07/01 23:07:43 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_list *list)
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
}

void	do_ra(t_list *list, t_final *final)
{
	r(list);
	final->moves++;
	write(1, "ra\n", 3);
}

void	do_rb(t_list *stack_b, t_final *final)
{
	r(stack_b);
	final->moves++;
	write(1, "rb\n", 3);
}

void	do_rr(t_list *list, t_list *stack_b, t_final *final)
{
	r(list);
	r(stack_b);
	final->moves++;
	write(1, "rr\n", 3);
}
