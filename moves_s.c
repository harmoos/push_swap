/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:41:19 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/29 18:21:41 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list *list, t_final *final)
{
	t_case	*node;
	int		tmp;

	if (list->size < 2)
		return (0);
	node = list->first;
	tmp = node->value;
	node->value = node->next->value;
	node->next->value = tmp;
	final->moves++;
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_list *list, t_final *final)
{
	t_case	*node;
	int		tmp;

	if (list->size < 2)
		return (0);
	node = list->first;
	tmp = node->value;
	node->value = node->next->value;
	node->next->value = tmp;
	final->moves++;
	write(1, "sb\n", 3);
	return (0);
}

void	ss(t_list *list, t_list *stack_b, t_final *final)
{
	sa(list, final);
	sb(stack_b, final);
	final->moves++;
	write(1, "ss\n", 3);
}
