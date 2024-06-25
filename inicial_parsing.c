/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicial_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:03:43 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/25 17:23:35 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	load(t_list *list, char *av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		while (av[i] == ' ')
			i++;
		j = i;
		if (av[i] == '+' || av[i] == '-')
			j++;
		if (av[i] == '\0')
			break ;
		while (av[j + 1] && (av[j + 1] >= '0' && av[j + 1] <= '9'))
			j++;
		if ((av[j] >= '0' && av[j] <= '9') && (!av[j + 1] || (av[j + 1] && av[j + 1] == ' ')))
			stack_add(list, av, i, j);
		else
			ft_exit(list, BADCHAR);
		i = j + 1;
	}
	return (1);
}

void	stack_add(t_list *list, char *av, int i, int j)
{
	t_case	*new;
	char	*strnum;

	new = lst_new();
	if (!new)
	{
		lst_add(list, new);
		ft_exit(list, "");
		return ;
	}
	strnum = ft_substr2(av, i, j + 1 - i);
	if (!strnum)
	{
		lst_add(list, new);
		ft_exit(list, "");
		return ;
	}
	new->value = (ft_new_atoi(list, &strnum, new));
	free(strnum);
	lst_add(list, new);
}

t_list	*pars(int ac, char **av)
{
	t_list	*list;
	int		i;

	list = lst_init();
	if (!list)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		if (!load(list, av[i]))
			return (NULL);
		i++;
	}
	check_doubles(list);
	return (list);
}
