/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:30:51 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/04 14:27:52 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

void	reverse_rot(t_stack **stack_ab)
{
	t_stack	*temp;

	if (*stack_ab == NULL || (*stack_ab)->next == NULL)
		return ;
	temp = *stack_ab;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp->next->next = *stack_ab;
	temp->next = NULL;
}

void	reverse_rot_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rot(stack_a);
	reverse_rot(stack_b);
}
