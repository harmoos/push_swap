/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:27:22 by nleoni            #+#    #+#             */
/*   Updated: 2024/07/02 20:39:30 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_init(t_list *list, t_list *stack_b, t_final *final)
{
	// t_case	*node;

	// node = list->first;
	print_stack(list);
	final->max = find_max_number(list);
	final->min = find_min_number(list);
	if (list->size < 2)
		return ;
	else if (list->size == 3)
		only_three(list, final);
	else
	{
		sorting_algo(list, stack_b, final);
		// while (list->size != 3 && node != NULL && !is_sorted(list))
		// {
		// 	if (node->value != final->max && node->value != final->min)
		// 		pb(list, stack_b, final);
		// 	else if (node->value == final->max || node->value == final->min)
		// 		do_ra(list, final);
		// 	node = list->first;
		// }
		// print_stack(list);
		// print_stack(stack_b);
		// only_three(list, final);
		// // print_stack(list);
		// check_count(list, stack_b, final);
		// final_sorting(list, final);
		// // print_stack(list);
		// printf("moves: %d\n", final->moves);
		// printf("sorted? %d\n", is_sorted(list));
		print_stack(list);
		print_stack(stack_b);
	}
}

int	find_target(t_list *list, int value)
{
	t_case	*node;
	int		pos;

	make_list_circular(list);
	pos = 0;
	node = list->first;
	while (node->next != list->first)
	{
		if (value > node->value && value < node->next->value)
		{
			make_list_linear(list);
			return (pos + 1);
		}
		pos++;
		node = node->next;
	}
	if (value > node->value && value < list->first->value)
	{
		make_list_linear(list);
		return (0);
	}
	make_list_linear(list);
	return (-1);
}

int	find_count(int target, int pos, int Asize, int Bsize)
{
	int p_count = 0;
	int	p_r_count = 0;
	int	t_count = 0;
	int	t_r_count = 0;

	if ((Bsize % 2) != 0 && pos == (Bsize / 2) + 1 && pos != 1)
		p_count = pos;
	else if (pos <= Bsize / 2 || pos == 1)
		p_count = pos - 1;
	else if (pos == Bsize && Bsize > 1)
		p_r_count = 1;
	else
		p_r_count = Bsize - pos + 1;
	if ((Asize % 2) != 0 && target == (Asize /2) + 1 && target != 1)
		t_count = target;
	else if (target <= Asize / 2 || target == 1)
		t_count = target - 1;
	else if (target == Asize && Asize > 1)
		t_r_count = 1;
	else
		t_r_count = Asize - target + 1;

	int count = p_count + t_count + 1;

	while (p_count > 0 && t_count > 0)
	{
		count--;
		p_count--;
		t_count--;
	}
	while (p_r_count > 0 && t_r_count > 0)
	{
		count--;
		p_r_count--;
		t_r_count--;
	}
	count += p_r_count + t_r_count;
	return count;
}

// void push_stack_a(t_list *list, t_list *stack_b, t_final *final)
// {
// 	if (final->pos <= (int)stack_b->size / 2 && final->pos != 1)
// 	{
// 		while (final->pos > 1)
// 		{
// 			rb(stack_b, final);
// 			final->pos--;
// 		}
// 	}
// 	else
// 	{
// 		while (((int)stack_b->size - final->pos + 1) > 0 && final->pos != 1)
// 		{
// 			rrb(stack_b, final);
// 			final->pos++;
// 		}
// 	}
// 	if (final->target <= ((int)list->size / 2))
// 	{
// 		while (final->target--)
// 			ra(list, final);
// 	}
// 	else if (final->target > ((int)list->size / 2))
// 	{
// 		while (((int)list->size - final->target) > 0)
// 		{
// 			rra(list, final);
// 			final->target++;
// 		}
// 	}
// 	pa(list, stack_b, final);
// }

void push_stack_a(t_list *list, t_list *stack_b, t_final *final)
{
	if (final->pos <= (int)stack_b->size / 2 && final->pos != 1)
	{
		while (final->pos > 1)
		{
			final->rb++;
			final->pos--;
		}
	}
	else
	{
		while (((int)stack_b->size - final->pos + 1) > 0 && final->pos != 1)
		{
			final->rrb++;
			final->pos++;
		}
	}
	if (final->target <= ((int)list->size / 2) && final->target != 0)
	{
		while (final->target > 0)
		{
			final->ra++;
			final->target--;
		}
	}
	else if (final->target > ((int)list->size / 2))
	{
		while (((int)list->size - final->target) > 0 && final->target != 0)
		{
			final->rra++;
			final->target++;
		}
	}
	// printf("ra: %d rb: %d rra: %d rrb: %d\n", final->ra, final->rb, final->rra, final->rrb);
	optm_push_r(list, stack_b, final);
	pa(list, stack_b, final);
	final_rr_init(final);
	printf("STACK A\n");
	print_stack(list);
	printf("STACK B\n");
	print_stack(stack_b);
}

void	check_count(t_list *list, t_list *stack_b, t_final *final)
{
	t_case	*node_b;

	node_b = stack_b->first;
	int pos = 1;
	int	target = 0;
	int	cout = 0;

	while (stack_b->size != 0)
	{
		while (node_b != NULL)
		{
			target = find_target(list, node_b->value);
			cout = find_count(target, pos, list->size, stack_b->size);
			printf("node->value: %d		cout: %d	target: %d		pos: %d\n", node_b->value, cout, target, pos);
			if (pos == 1)
			{
				final->cost = cout;
				final->pos = pos;
				final->target = target;
			}
			else if (cout < final->cost)
			{
				final->cost = cout;
				final->pos = pos;
				final->target = target;
			}
			pos++;
			node_b = node_b->next;
		}
		push_stack_a(list, stack_b, final);
		pos = 1;
		node_b = stack_b->first;
		final_re_inicialize(final);
	}
}
