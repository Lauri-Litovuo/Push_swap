/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:27:46 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/11 14:59:45 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

void	push_ab(t_stack **stack_from, t_stack **stack_to, char ch)
{
	t_stack	*pushed;

	if (stack_from == NULL)
		return ;
	pushed = *stack_from;
	*stack_from = pushed->next;
	pushed->next = *stack_to;
	*stack_to = pushed;
	ft_printf("p%c", ch);
}
