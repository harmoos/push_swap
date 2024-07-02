/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:24:21 by nleoni            #+#    #+#             */
/*   Updated: 2024/07/02 20:38:12 by nleoni           ###   ########.fr       */
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
	int	max;
	int	min;
	int	moves;
	int	pa;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_final;

int		ft_new_atoi(t_list *list, char **str, t_case *new);
int		check_doubles(t_list *list);
int		is_sorted(t_list *list);
int		load(t_list *list, char *av);
int		find_max_number(t_list *list);
int		find_min_number(t_list *list);
int		sa(t_list *list, t_final *final);
int		sb(t_list *list, t_final *final);
void	ss(t_list *list, t_list *stack_b, t_final *final);
int		pa(t_list *list, t_list *stack_b, t_final *final);
int		pb(t_list *list, t_list *stack_b, t_final *final);
void	r(t_list *list);
void	rr(t_list *list);
char	*ft_substr2(char const *s, unsigned int start, size_t len);
void	lst_add(t_list *list, t_case *new);
void	ft_exit(t_list *list, char *msg);
void	print_stack(t_list *list);
void	stack_add(t_list *list, char *av, int i, int j);
void	delete_stack(t_list *list);
void	only_two(t_list *list);
void	only_three(t_list *list, t_final *final);
void	algo_init(t_list *list, t_list *stack_b, t_final *final);
int		find_target(t_list *list, int value);
int		find_count(int target, int pos, int Asize, int Bsize);
void	push_stack_a(t_list *list, t_list *stack_b, t_final *final);
void	check_count(t_list *list, t_list *stack_b, t_final *final);
void	make_list_circular(t_list *list);
void	make_list_linear(t_list *list);
void	final_re_inicialize(t_final *final);
void	final_sorting(t_list *list, t_final *final);
void	optm_push_r(t_list *list, t_list *stack_b, t_final *final);
void	optm_push_rr(t_list *list, t_list *stack_b, t_final *final);
void	final_rr_init(t_final *final);
int		mod(int nb);
void	do_ra(t_list *list, t_final *final);
void	do_rb(t_list *stack_b, t_final *final);
void	do_rr(t_list *list, t_list *stack_b, t_final *final);
void	do_rra(t_list *list, t_final *final);
void	do_rrb(t_list *stack_b, t_final *final);
void	do_rrr(t_list *list, t_list *stack_b, t_final *final);
void	sorting_algo(t_list *list, t_list *stack_b, t_final *final);
t_case	*lst_new(void);
t_list	*lst_init(void);
t_list	*lst_init_b(void);
t_list	*pars(int ac, char **av);

#endif
