/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:01:54 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/11 12:13:00 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHLIB_H
# define PUSHLIB_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h> //delete this

typedef struct s_stack
{
	int				content;
	int				size;
	struct s_stack	*next;
}				t_stack;

t_stack	*ft_stacknew(int content);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	push_ab(t_stack **stack_from, t_stack **stack_to);
void	swap_ab(t_stack **stack);
void	swap_simult(t_stack **stack_a, t_stack **stack_b);
void	rotate_ab(t_stack **stack);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rot(t_stack **stack_ab);
void	reverse_rot_both(t_stack **stack_a, t_stack **stack_b);
t_stack	*make_stack(t_stack	**stack, char **elem_list, int count);
t_stack	*input_to_list(int ac, char **av);
int		count_elements(char *str);
int		validate_input(char **elem_list, int count);

#endif