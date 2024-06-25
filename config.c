/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:58:24 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/14 19:51:43 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_list *list)
{
	t_case	*current;
	t_case	*tmp;

	current = list->first;
	while (current->next != NULL)
	{
		tmp = current->next;
		while (tmp != NULL)
		{
			if (current->value == tmp->value)
				return (ft_exit(list, DOUBLES), 1);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (0);
}
