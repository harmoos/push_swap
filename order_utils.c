/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:52:33 by nleoni            #+#    #+#             */
/*   Updated: 2024/07/01 23:06:12 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_case	*node;
	t_case	*node_next;

	if (list->size < 2)
		return (1);
	node = list->first;
	node_next = node->next;
	while (node_next != NULL)
	{
		if (node->value > node_next->value)
			return (0);
		node = node_next;
		node_next = node_next->next;
	}
	return (1);
}

int	find_max_number(t_list *list)
{
	t_case	*node;
	int		max;

	if (list->size < 1)
		return (0);
	node = list->first;
	max = node->value;
	while (node->next != NULL)
	{
		node = node->next;
		if (node->value > max)
			max = node->value;
	}
	return (max);
}

int	find_min_number(t_list *list)
{
	t_case	*node;
	int		min;

	if (list->size < 1)
		return (0);
	node = list->first;
	min = node->value;
	while (node->next != NULL)
	{
		node = node->next;
		if (node->value < min)
			min = node->value;
	}
	return (min);
}

void	make_list_circular(t_list *list)
{
	t_case	*last;

	last = list->first;
	if (list->first == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	last->next = list->first;
}

void	make_list_linear(t_list *list)
{
	t_case	*last;

	last = list->first;
	if (list->first == NULL)
		return ;
	while (last->next != list->first)
		last = last->next;
	last->next = NULL;
}

void	only_two(t_list *list)
{
	if (list->size == 2 && list->first->value > list->first->next->value)
	{
		sa(list, 0);
		return ;
	}
}

void	only_three(t_list *list, t_final *final)
{
	t_case	*first;
	t_case	*second;
	t_case	*third;
	int		max;

	if (list->size != 3 || (is_sorted(list)))
		return ;
	first = list->first;
	second = first->next;
	third = second->next;
	max = find_max_number(list);
	if (third->value == max)
	{
		if (first->value > second->value)
			sa(list, final);
	}
	else if (first->value == max)
		do_ra(list, final);
	else if (second->value == max)
		do_rra(list, final);
	if (!is_sorted(list))
		only_three(list, final);
}
