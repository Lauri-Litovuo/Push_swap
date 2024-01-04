/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:04:51 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/04 14:25:45 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

void	rotate_ab(t_stack **stack)
{
	t_stack	*head;
	t_stack	*iter;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	iter = *stack;
	stack = iter->next;
	while (iter != NULL)
	{
		iter = iter->next;
	}
	iter->next = head;
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	rotate_ab(stack_a);
	rotate_ab(stack_b);
}
