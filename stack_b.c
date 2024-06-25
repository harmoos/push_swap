/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:29:12 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/14 19:33:45 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_init_b(void)
{
	t_list	*stack_b;

	stack_b = (t_list *)malloc(sizeof(t_list));
	if (!stack_b)
		return (NULL);
	stack_b->size = 0;
	stack_b->first = 0;
	return (stack_b);
}
