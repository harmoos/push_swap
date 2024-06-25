/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:27:22 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/25 21:26:24 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_init(t_list *list, t_list *stack_b)
{
	if (list->size < 2)
		return ;
	else if (list->size == 3)
		only_three(list);
	else
	{
		while (list->size > 3)
			pb(list, stack_b, 1);
		only_three(list);
		check_count(list, stack_b);
		print_stack(stack_b);
		print_stack(list);
	}
}

int	find_target(t_list *list, int value)
{
	t_case	*node_a;
	int		pos = 0;

	node_a = list->first;
	while (node_a->next != NULL && value > node_a->value)
	{
		pos++;
		node_a = node_a->next;
	}
	return (pos);
}

int	find_cout(int target, int pos, int Asize, int Bsize)
{
	if (pos > (Bsize / 2))
		pos = Bsize - pos;
	else if (pos < (Bsize / 2))
		pos = pos;
	if (target > (Asize / 2))
		target = Asize - target;
	else if (target == Asize - 1)
		target = 1;
	else if (target < (Asize / 2))
		target = target;
	return (target + pos + 1);
}

void	calcul_move(t_final *final, int Bsize, int Asize)
{
	//printf("pos: %d 	target: %d 	cost: %d 	\n", final->pos, final->target, final->cost);
	if (final->pos > (Bsize / 2))
		final->rrb = Bsize - final->pos;
	else if (final->pos < (Bsize / 2))
		final->rb = final->pos;
	if (final->target > (Asize / 2))
		final->rra = Asize - final->target;
	else if (final->target == Asize - 1)
		final->rra = 1;
	else if (final->target < (Asize / 2))
		final->ra = final->target;
	final->pa = 1;
	//printf("HELLOrrb: %d		rb: %d		rra: %d		ra: %d		pa: %d\n", final->rrb, final->rb, final->rra, final->ra, final->pa);
}

void	push_stack_a(t_list *list, t_list *stack_b, t_final final)
{
	calcul_move(&final, stack_b->size, list->size);
	//printf("rrb: %d		rb: %d		rra: %d		ra: %d		pa: %d\n", final.rrb, final.rb, final.rra, final.ra, final.pa);
	while (final.rrb-- != 0)
		rrb(stack_b, 1);
	while (final.rb-- != 0)
		rb(stack_b, 1);
	pa(list, stack_b, 1);
	while (final.rra-- != 0)
		rra(list, 1);
	while (final.ra-- != 0)
		ra(list, 1);
}
void	check_count(t_list *list, t_list *stack_b)
{
	t_case	*node_b;

	node_b = stack_b->first;
	int pos = 0;
	int	target = 0;
	int	cout = 0;
	t_final final;

	final = (t_final){0};
	while (stack_b->size != 0)
	{
		while (node_b != NULL)
		{
			target = find_target(list, node_b->value);
			cout = find_cout(target, pos, list->size, stack_b->size);
			printf("ici :                 %d\n", final.cost);
			if (pos == 0)
			{
				final.cost = cout;
				final.pos = pos;
				final.target = target;
			}
			else if (cout < final.cost)
			{
				final.cost = cout;
				final.pos = pos;
				final.target = target;
			}
				printf("pos: %d 	target: %d 	cost: %d\n", pos, target, cout);
			pos++;
			//printf("%i\n", node_b->value);
			node_b = node_b->next;
		}
		//printf("pos: %d 	target: %d 	cost: %d 	pos : %d\n", final.pos, final.target, final.cost, pos);
		push_stack_a(list, stack_b, final);
		pos = 0;
		final = (t_final){0};
	}
}
