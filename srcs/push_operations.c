/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:27:46 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/29 12:39:31 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

/**
 * @brief Takes the first element at the top of a/b and put it at the top of b/a.
Do nothing if from stack is empty.
 * 
 * @param stack_from 
 * @param stack_to 
 * @param to Character 'a' or 'b' to represent target stack.
 */

void	push_ab(t_stack **stack_from, t_stack **stack_to, char to)
{
	t_stack	*pushed;

	if (*stack_from == NULL)
		return ;
	pushed = *stack_from;
	*stack_from = pushed->next;
	pushed->next = *stack_to;
	*stack_to = pushed;
	ft_printf("p%c\n", to);
}
