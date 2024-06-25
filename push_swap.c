/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:23:22 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/25 17:36:53 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_list *list, char *msg)
{
	delete_stack(list);
	ft_printf("ERROR:\n%s\n", msg);
	exit(0);
}

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*dest;

	if (!s)
		return (0);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	i = 0;
	if (start < ft_strlen((char *)s))
	{
		while (s[start + i] && (size_t)i < len)
		{
			dest[i] = s[start + i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

int	is_digit3(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_digit2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' && str[i] > '9') || str[i] == ' ')
			return (1);
	}
	return (0);
}

int	ft_new_atoi(t_list *list, char **str, t_case *new)
{
	int					tab[2];
	long int			r;
	unsigned long long	result;
	char				*s;

	tab[0] = 0;
	tab[1] = 1;
	result = 0;
	s = *str;
	while ((s[tab[0]] == ' ') || (s[tab[0]] >= 9 && s[tab[0]] <= 13))
		tab[0]++;
	if (s[tab[0]] == '-')
		tab[1] = -1;
	if ((s[tab[0]] == '+') || (s[tab[0]] == '-'))
		tab[0]++;
	while (ft_isdigit(s[tab[0]]))
		result = (result * 10) + (s[tab[0]++] - 48);
	r = result * tab[1];
	if (r > 2147483647 || r < -2147483647)
	{
		free(new);
		free(*str);
		ft_exit(list, INTP);
	}
	return ((int)result * tab[1]);
}

int	main(int ac, char **av)
{
	t_list	*list;
	t_list	*stack_b;

	list = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (1);
	list = pars(ac, av);
	if (!list)
		return (1);
	stack_b = lst_init_b();
	algo_init(list, stack_b);
	// print_stack(list);
	delete_stack(list);
	delete_stack(stack_b);
	return (0);
}
