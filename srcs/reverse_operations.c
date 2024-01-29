/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:30:51 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/29 12:27:28 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

/**
 * @brief Shifts down all elements of a stack by 1.
The last element becomes the first one.
 * 
 * @param stack_ab stack to be reverse rotated
 * @param ch stack identifier a/b
 */

void	reverse_rot(t_stack **stack_ab, char ch)
{
	t_stack	*temp;

	if (stack_ab == NULL || (*stack_ab)->next == NULL)
		return ;
	temp = *stack_ab;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp->next->next = *stack_ab;
	*stack_ab = temp->next;
	temp->next = NULL;
	if (ch == 'a' || ch == 'b')
		ft_printf("rr%c\n", ch);
}

void	reverse_rot_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rot(stack_a, 'c');
	reverse_rot(stack_b, 'c');
	ft_printf("rrr\n");
}
