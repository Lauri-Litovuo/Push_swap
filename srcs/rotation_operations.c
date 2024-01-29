/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:04:51 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/29 12:27:39 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

/**
 * @brief Shifts up all elements of a stack by 1.
 * The first element at the stack becomes the last one.
 * 
 * @param stack Stack where it is implemented
 * @param ch stack identifier a/b
 */

void	rotate_ab(t_stack **stack, char ch)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	ft_stackadd_back(stack, *stack);
	*stack = temp->next;
	temp->next = NULL;
	if (ch == 'a' || ch == 'b')
		ft_printf("r%c\n", ch);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_ab(stack_a, 'c');
	rotate_ab(stack_b, 'c');
	ft_printf("rr\n");
}
