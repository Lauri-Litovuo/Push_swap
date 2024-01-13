/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:16:33 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/13 19:11:06 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

static void	two_elements(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	if (temp->next->next == NULL)
	{
		if (temp->next->content > temp->content)
			return ;
		else
			swap_ab(&stack_a, 'a');
	}
}

static void	three_elements(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;

	if (temp->size == 2)
	{
		temp = temp->next;
		if (temp->size == 1)
			swap_ab(&stack_a, 'a');
		else
			reverse_rot(&stack_a, 'a');
	}
	if (temp->size == 3)
	{
		temp = temp->next;
		if (temp->size == 1)
			rotate_ab(&stack_a, 'a');
		else
		{
			rotate_ab(&stack_a, 'a');
			swap_ab(&stack_a, 'a');
		}
	}
}

void	mini_algo(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	if (temp->next->next == NULL)
	{
		two_elements(&stack_a);
		return ;
	}
	if (temp->size == 1)
	{
		temp = temp->next;
		if (temp->size == 3)
		{
			reverse_rot(&stack_a, 'a');
			swap_ab(&stack_a, 'a');
		}
		else
			return ;
	}
	else
		three_elements(&stack_a);
}

