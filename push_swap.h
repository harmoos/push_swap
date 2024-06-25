/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:24:21 by nleoni            #+#    #+#             */
/*   Updated: 2024/06/25 20:22:24 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

# define BADCHAR "Charactheres not authorized"
# define DOUBLES "Double numbers in the list"
# define INTP "INT MAX ou INT MIN"

typedef struct s_case	t_case;

typedef struct s_case
{
	int		value;
	t_case	*next;
}	t_case;

typedef struct s_list
{
	t_case	*first;
	size_t	size;
}	t_list;

typedef struct s_final
{
	int pos;
	int target;
	int	cost;
	int	pa;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_final;

int		is_digit2(char *str);
int		is_digit3(char c);
int		ft_new_atoi(t_list *list, char **str, t_case *new);
int		check_doubles(t_list *list);
int		is_sorted(t_list *list);
int		load(t_list *list, char *av);
int		find_max_number(t_list *list);
int		sa(t_list *list, int a);
int		sb(t_list *list, int a);
void	ss(t_list *list, t_list *stack_b);
int		pa(t_list *list, t_list *stack_b, int a);
int		pb(t_list *list, t_list *stack_b, int a);
void	ra(t_list *list, int a);
void	rb(t_list *stack_b, int a);
void	rr(t_list *list, t_list *stack_b, int a);
void	rra(t_list *list, int a);
void	rrb(t_list *stack_b, int a);
void	rrr(t_list *list, t_list *stack_b, int a);
char	*ft_substr2(char const *s, unsigned int start, size_t len);
void	lst_add(t_list *list, t_case *new);
void	ft_exit(t_list *list, char *msg);
void	print_stack(t_list *list);
void	stack_add(t_list *list, char *av, int i, int j);
void	delete_stack(t_list *list);
void	only_two(t_list *list);
void	only_three(t_list *list);
void	only_four(t_list *list, t_list *stack_b);
void	four_outil(t_list *list, t_list *stack_b, int b);
void	only_five(t_list *list, t_list *stack_b);
void	algo_init(t_list *list, t_list *stack_b);
int		find_target(t_list *list, int value);
int		find_cout(int target, int pos, int Asize, int Bsize);
void	push_stack_a(t_list *list, t_list *stack_b, t_final final);
void	check_count(t_list *list, t_list *stack_b);
void	calcul_move(t_final *final, int Bsize, int Asize);
t_case	*lst_new(void);
t_list	*lst_init(void);
t_list	*lst_init_b(void);
t_list	*pars(int ac, char **av);

#endif
