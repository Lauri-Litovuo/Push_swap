/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:19:50 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/29 12:27:48 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

/**
 * @brief Swaps the first 2 elements at the top of a stack. 
 * Does nothing if there is only one or no elements. 
 * Swap simult swaps both stacks.
 * 
 * @param stack 
 * @param ch 
 */

void	swap_ab(t_stack **stack, char ch)
{
	t_stack	*temp;
	t_stack	*third;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
		return ;
	third = temp->next->next;
	temp = temp->next;
	temp->next = *stack;
	temp->next->next = third;
	*stack = temp;
	if (ch == 'a' || ch == 'b')
		ft_printf("s%c\n", ch);
}

void	swap_simult(t_stack **stack_a, t_stack **stack_b)
{
	swap_ab(stack_a, 'c');
	swap_ab(stack_b, 'c');
	ft_printf("ss\n");
}
