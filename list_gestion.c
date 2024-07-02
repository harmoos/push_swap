/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_gestion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:38:30 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/30 16:16:03 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_add(t_list *list, t_case *new)
{
	t_case	*current;

	if (list->first == NULL)
	{
		list->first = new;
		new->next = NULL;
	}
	else
	{
		current = list->first;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->next = NULL;
	}
	list->size++;
}

t_list	*lst_init(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->size = 0;
	list->first = 0;
	return (list);
}

t_case	*lst_new(void)
{
	t_case	*new;

	new = (t_case *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	print_stack(t_list *list)
{
	t_case	*current;

	if (list == NULL)
	{
		printf("List is empty\n");
		return ;
	}
	current = list->first;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("list->size: %ld\n", list->size);
}

void	delete_stack(t_list *list)
{
	t_case	*current;
	t_case	*next_node;

	if (list == NULL)
		return ;
	current = list->first;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(list);
}

void	final_re_inicialize(t_final *final)
{
	final->pos = 1;
	final->target = 0;
	final->cost = 0;
}

void	final_rr_init(t_final *final)
{
	final->ra = 0;
	final->rb = 0;
	final->rra = 0;
	final->rrb = 0;
}
