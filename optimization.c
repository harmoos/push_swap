/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:33:05 by nleoni            #+#    #+#             */
/*   Updated: 2024/07/02 21:15:50 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sorting(t_list *list, t_final *final)
{
	t_case	*node;
	int		pos;

	node = list->first;
	pos = 0;
	while (node->next != NULL)
	{
		if (final->min == node->value)
			break ;
		pos++;
		node = node->next;
	}
	while (!is_sorted(list))
	{
		if (pos > (int)(list->size / 2))
			do_rra(list, final);
		else
			do_ra(list, final);
	}
}

void	sorting_algo(t_list *list, t_list *stack_b, t_final *final)
{
	t_case	*node;
	// t_case	*second;
	int		tmp;
	// int		second_tmp;

	tmp = INT_MIN;
	while (!is_sorted(list))
	{
		node = list->first;
		while (node != NULL && node->next != NULL)
		{
			// second = list->first;
			// while (second->next != NULL)
			// 	second = second->next;
			// second_tmp = second->value;
			if ((node->value == final->min || node->value == final->max) && list->first->value != final->min)
				pb(list, stack_b, final);
			else if (node->value < node->next->value)
			{
				tmp = node->value;
				do_ra(list, final);
			}
			else if (node->value > node->next->value && tmp < node->next->value)
			{
				tmp = node->value;
				sa(list, final);
				do_ra(list, final);
			}
			else
				pb(list, stack_b, final);
			printf("node: %d\n", node->value);
			node = node->next;
		}
	}
	printf("STACK A\n");
	print_stack(list);
}

int	mod(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

// void	optm_push_r(t_list *list, t_list *stack_b, t_final *final)
// {
// 	int	r;

// 	r = mod(final->rb - final->ra);
// 	if (final->rb == final->ra && final->rb != 0 && final->ra != 0)
// 	{
// 		while (final->rb > 0 && final->ra > 0)
// 		{
// 			do_rr(list, stack_b, final);
// 			final->rb--;
// 			final->ra--;
// 		}
// 	}
// 	else if (r > 0 && final->rb > 0 && final->ra > 0)
// 	{
// 		while (r > 0)
// 		{
// 			do_rr(list, stack_b, final);
// 			final->rb--;
// 			final->ra--;
// 			r--;
// 		}
// 		if (final->rb - final->ra > 0)
// 		{
// 			do_rb(stack_b, final);
// 			final->rb--;
// 		}
// 		else if (final->ra - final->rb > 0)
// 		{
// 			do_ra(stack_b, final);
// 			final->ra--;
// 		}
// 	}
// 	else if (final->rb > 0 && final->ra == 0)
// 	{
// 		while (final->rb > 0)
// 		{
// 			do_rb(stack_b, final);
// 			final->rb--;
// 		}
// 	}
// 	else if (final->ra > 0 && final->rb == 0)
// 	{
// 		while (final->ra > 0)
// 		{
// 			do_ra(list, final);
// 			final->ra--;
// 		}
// 	}
// 	optm_push_rr(list, stack_b, final);
// }

void optm_push_r(t_list *list, t_list *stack_b, t_final *final)
{
	while (final->rb > 0 && final->ra > 0)
	{
		do_rr(list, stack_b, final);
		final->rb--;
		final->ra--;
	}
	while (final->rb > 0)
	{
		do_rb(stack_b, final);
		final->rb--;
	}
	while (final->ra > 0)
	{
		do_ra(list, final);
		final->ra--;
	}
	optm_push_rr(list, stack_b, final);
}

// void	optm_push_rr(t_list *list, t_list *stack_b, t_final *final)
// {
// 	int	r;

// 	r = mod(final->rrb - final->rra);
// 	if (final->rrb == final->rra && final->rrb != 0 && final->rra != 0)
// 	{
// 		while (final->rrb > 0 && final->rra > 0)
// 		{
// 			do_rrr(list, stack_b, final);
// 			final->rb--;
// 			final->ra--;
// 		}
// 	}
// 	else if (r > 0 && final->rrb > 0 && final->rra > 0)
// 	{
// 		while (r > 0 && final->rra != 0 && final->rrb != 0)
// 		{
// 			do_rrr(list, stack_b, final);
// 			final->rrb--;
// 			final->rra--;
// 			r--;
// 		}
// 		if (final->rrb - final->rra > 0)
// 		{
// 			do_rrb(stack_b, final);
// 			final->rrb--;
// 		}
// 		else if (final->rra - final->rrb > 0)
// 		{
// 			do_rra(stack_b, final);
// 			final->rra--;
// 		}
// 	}
// 	else if (final->rrb > 0 && final->rra == 0)
// 	{
// 		while (final->rrb > 0)
// 		{
// 			do_rrb(stack_b, final);
// 			final->rrb--;
// 		}
// 	}
// 	else if (final->rra > 0 && final->rrb == 0)
// 	{
// 		while (final->rra > 0)
// 		{
// 			do_rra(list, final);
// 			final->rra--;
// 		}
// 	}
// }

void optm_push_rr(t_list *list, t_list *stack_b, t_final *final)
{
	while (final->rrb > 0 && final->rra > 0)
	{
		do_rrr(list, stack_b, final);
		final->rrb--;
		final->rra--;
	}
	while (final->rrb > 0)
	{
		do_rrb(stack_b, final);
		final->rrb--;
	}
	while (final->rra > 0)
	{
		do_rra(list, final);
		final->rra--;
	}
}
