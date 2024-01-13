/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:04:51 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/13 17:55:56 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

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
