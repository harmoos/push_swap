/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:41:19 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/15 14:35:50 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list *list, int a)
{
	t_case	*node;
	int		tmp;
	
	if (list->size < 2)
		return (0);
	node = list->first;
	tmp = node->value;
	node->value = node->next->value;
	node->next->value = tmp;
	if (a)
		write(1, "sa\n", 3);
	return (0);
}

int	sb(t_list *list, int a)
{
	t_case	*node;
	int		tmp;
	
	if (list->size < 2)
		return (0);
	node = list->first;
	tmp = node->value;
	node->value = node->next->value;
	node->next->value = tmp;
	if (a)
		write(1, "sb\n", 3);	
	return (0);
}

void	ss(t_list *list, t_list *stack_b)
{
	sa(list, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}
