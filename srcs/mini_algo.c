/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:16:33 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/16 13:34:19 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

static void	two_elements(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	if (temp->next->index > temp->index)
		return ;
	else
		swap_ab(stack_a, 'a');
}

static void	three_elements(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	if (temp->index == 1)
	{
		temp = temp->next;
		if (temp->index == 0)
			swap_ab(stack_a, 'a');
		else
			reverse_rot(stack_a, 'a');
	}
	else
	{
		temp = temp->next;
		if (temp->index == 0)
			rotate_ab(stack_a, 'a');
		else
		{
			rotate_ab(stack_a, 'a');
			swap_ab(stack_a, 'a');
		}
	}
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	if (temp->next->next == 0)
	{
		two_elements(stack_a);
		return ;
	}
	else if (temp->index == 0)
	{
		temp = temp->next;
		if (temp->index == 2)
		{
			reverse_rot(stack_a, 'a');
			swap_ab(stack_a, 'a');
		}
		else
			return ;
	}
	else
		three_elements(stack_a);
}
