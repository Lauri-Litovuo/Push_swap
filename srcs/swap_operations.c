/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:19:50 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/10 10:17:01 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"
#include "../libft/libft.h"

void	swap_ab(t_stack **stack)
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
}

void	swap_simult(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	swap_ab(stack_a);
	swap_ab(stack_b);
}
