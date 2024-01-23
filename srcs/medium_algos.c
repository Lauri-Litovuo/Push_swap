/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:56:39 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/23 14:18:33 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

void	rotate_to_top(t_stack **stack_ab, int pos, char ab)
{
	int		size;
	t_stack	*temp;

	temp = *stack_ab;
	size = ft_stacksize(temp);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rotate_ab(stack_ab, ab);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			reverse_rot(stack_ab, ab);
			pos--;
		}
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		pos;

	pos = 0;
	temp = *stack_a;
	while (temp->index != 3)
	{
		temp = temp->next;
		pos++;
	}
	rotate_to_top(stack_a, pos, 'a');
	temp = *stack_a;
	push_ab(stack_a, stack_b, 'b');
	sort_three(stack_a);
	push_ab(stack_b, stack_a, 'a');
	rotate_ab(stack_a, 'a');
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		pos;

	pos = 0;
	temp = *stack_a;
	while (temp->index != 4)
	{
		temp = temp->next;
		pos++;
	}
	rotate_to_top(stack_a, pos, 'a');
	push_ab(stack_a, stack_b, 'b');
	sort_four(stack_a, stack_b);
	push_ab(stack_b, stack_a, 'a');
	rotate_ab(stack_a, 'a');
}
