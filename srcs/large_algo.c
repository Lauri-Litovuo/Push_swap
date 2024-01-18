/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:08:14 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/18 16:34:07 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

static int	check_indexs(t_stack *node, t_stack *next_node)
{
	int	sorted;

	sorted = 0;
	while (!next_node)
	{
		if (node->index < next_node->index)
		{
			node = node->next;
			next_node = next_node->next;
		}
		else
		{
			sorted = 1;
			break ;
		}
	}
	return (sorted);
}

static int	check_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*next_node;
	int		a_sorted;
	int		b_sorted;

	a_sorted = 1;
	node = *stack_a;
	next_node = (*stack_a)->next;
	a_sorted = check_indexs(node, next_node);
	node = *stack_b;
	next_node = (*stack_b)->next;
	b_sorted = check_indexs(node, next_node);
	if (a_sorted == 1 && b_sorted == 0)
		return (1);
	else if (a_sorted == 0 && b_sorted == 1)
		return (2);
	else if (a_sorted == 1 && b_sorted == 1)
		return (3);
	else
		return (0);
}


static void	swap_and_rotate(t_stack **stack_a, t_stack **stack_b)
{
	int		sorted;
	t_stack	*a;
	t_stack	*b;
	t_stack *temp;

	sorted = 0;
	a = *stack_a;
	b = *stack_b;
	while (sorted != 3)
	{
		if (a->index < a->next->index && b->index < b->next->index)
			swap_simult(stack_a, stack_b);
		if (a->index < a->next->index && b->index > b->next->index)
			swap_ab(stack_a, 'a');
		if (a->index > a->next->index && b->index < b->next->index)
			swap_ab(stack_b, 'b');
		sorted = check_sort(stack_a, stack_b);
		if (sorted == 0)
			rotate_both(stack_a, stack_b);
		if (sorted == 1)
			rotate_ab(stack_b, 'b');
		if (sorted == 2)
			rotate_ab(stack_a, 'a');
		temp = *stack_a;
		while (temp != NULL)
		{
			ft_printf("%d\n", temp->content);
			temp = temp->next;
		}
		temp = *stack_b;
		while (temp != NULL)
		{
			ft_printf("stack b;%d\n", temp->content);
			temp = temp->next;
		}
		a = *stack_a;
		b = *stack_b;
		sleep(1);
	}
}

void	divide_by_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		size;
	int		start_size;

	temp = *stack_a;
	start_size = ft_stacksize(temp);
	size = start_size;
	while (size > (start_size / 2))
	{
		if ((*stack_a)->index >= (start_size / 2))
		{
			push_ab(stack_a, stack_b, 'b');
		}
		else
			rotate_ab(stack_a, 'a');
		temp = *stack_a;
		size = ft_stacksize(temp);
	}
}

void	large_algo(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	
	divide_by_index(stack_a, stack_b);
	temp = *stack_a;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
	temp = *stack_b;
	while (temp != NULL)
	{
		ft_printf("stack b;%d\n", temp->content);
		temp = temp->next;
	}
	sleep(5);
	swap_and_rotate(stack_a, stack_b);
}
