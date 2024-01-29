/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:27:53 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/29 13:23:57 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

/**
 * @brief Function finds the minimum value from the list that does not have
 * an index given and returns it.
 * 
 * @param stack_ab 
 * @return t_stack* 
 */

static t_stack	*assign_min(t_stack **stack_ab)
{
	int		flag;
	t_stack	*temp;
	t_stack	*min;

	flag = 0;
	temp = *stack_ab;
	while (temp != 0)
	{
		if (temp->index == -1 && (flag == 0 || min->content > temp->content))
		{
			min = temp;
			flag = 1;
		}
		temp = temp->next;
	}
	return (min);
}

/**
 * @brief Gives indexes to linked list stack elements from smallest to biggest
 * content int value.
 * 
 * @param stack_ab 
 */

void	give_index(t_stack **stack_ab)
{
	t_stack	*temp;
	t_stack	*cur_min;
	int		cur_index;
	int		count;

	cur_index = 0;
	temp = *stack_ab;
	count = ft_stacksize(temp);
	while (temp != NULL && cur_index < count)
	{
		cur_min = assign_min(&temp);
		cur_min->index = cur_index;
		cur_index++;
	}
}
