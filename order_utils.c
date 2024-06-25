/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:52:33 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/20 01:51:10 by nleoni           ###   ########.fr       */
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

void	only_two(t_list *list)
{
	if (list->size == 2 && list->first->value > list->first->next->value)
	{
		sa(list, 0);
		return ;
	}
}

void	only_three(t_list *list)
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
			sa(list, 1);
	}
	else if (first->value == max)
		ra(list, 1);
	else if (second->value == max)
		rra(list, 1);
	if (!is_sorted(list))
		only_three(list);
}

void	four_outil(t_list *list, t_list *stack_b, int b)
{
	if (b == 0)
	{
		pb(list, stack_b, 1);
		only_three(list);
		pa(list, stack_b, 1);
		ra(list, 1);
	}
	else
	{
		only_three(list);
		pa(list, stack_b, 1);
		ra(list, 1);
	}
}

void	only_four(t_list *list, t_list *stack_b)
{
	t_case	*node;
	int		max;

	if (list->size != 4 || (is_sorted(list)))
		return ;
	node = list->first;
	max = find_max_number(list);
	if (node->value == max)
		four_outil(list, stack_b, 0);
	else if (node->next->value == max)
	{
		pb(list, stack_b, 1);
		pb(list, stack_b, 1);
		sb(stack_b, 1);
		pa(list, stack_b, 1);
		four_outil(list, stack_b, 1);
	}
	else if (node->next->next->value == max)
	{
		rra(list, 1);
		rra(list, 1);
		four_outil(list, stack_b, 0);
	}
	else
	{
		rra(list, 1);
		four_outil(list, stack_b, 0);
	}
}

void	five_algo(t_list *list, t_list *stack_b, int max)
{
	t_case	*node;
	int		i;

	node = list->first;
	i = 0;
	if ((stack_b->first->value < node->value) && (stack_b->first->value < node->next->value))
		pa(list, stack_b, 1);
	if (stack_b->first->value == max)
	{
		pa(list, stack_b, 1);
		ra(list, 1);
	}
	else
	{
		while (node->next != NULL)
		{ /*loop infinito ?????????*/
			if (stack_b->first->value > node->value)
			{
				printf("i: %d\n", i);
				ra(list, 1);
				node = list->first;
				printf("node->value: %d\n", node->value);
				i++;
			}
			pa(list, stack_b, 1);
			while (i-- > 0)
				rra(list, 1);
		}
	}
	print_stack(list);
}

void	only_five(t_list *list, t_list *stack_b)
{
	// t_case	*node;
	int		max;
	// int		tmp_max;

	if (list->size != 5 || is_sorted(list))
		return ;
	max = find_max_number(list);
	// node = list->first;
	pb(list, stack_b, 1);
	pb(list, stack_b, 1);
	only_three(list);
	// tmp_max = find_max_number(list);
	// if (max != tmp_max)
	// {
	// 	if (stack_b->first->value == max)
	// 	{
	// 		pa(list, stack_b, 1);
	// 		ra(list, 1);
	// 		five_algo(list, stack_b);
	// 	}
	// 	else
	// 	{
	// 		rb(stack_b, 1);
	// 		pa(list, stack_b, 1);
	// 		ra(list, 1);
	// 		five_algo(list, stack_b);
	// 	}
	// }
	// else
	// {
		five_algo(list, stack_b, max);
		five_algo(list, stack_b, max);
	// }

}
