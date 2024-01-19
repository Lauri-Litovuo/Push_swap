/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:01:54 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/19 14:35:29 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHLIB_H
# define PUSHLIB_H
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h> //delete this

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}				t_stack;

t_stack	*ft_stacknew(int content);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int		ft_stacksize(t_stack *stack);
void	push_ab(t_stack **stack_from, t_stack **stack_to, char ch);
void	swap_ab(t_stack **stack, char ch);
void	swap_simult(t_stack **stack_a, t_stack **stack_b);
void	rotate_ab(t_stack **stack, char ch);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rot(t_stack **stack_ab, char ch);
void	reverse_rot_both(t_stack **stack_a, t_stack **stack_b);
t_stack	*make_stack(t_stack	**stack, char **elem_list, int count);
t_stack	*input_to_list(int ac, char **av);
int		count_elements(char *str);
int		validate_input(char **elem_list, int count);
void	give_index(t_stack **stack_ab);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	sorter_guider(t_stack **stack_a, t_stack **stack_b, int ac);

#endif