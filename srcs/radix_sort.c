/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:08:14 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/29 12:38:00 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

/**
 * @brief Checks if stack is sorted or not
 * 
 * @param stack_ab 
 * @return int Returns 1 if sorted 0 if not.
 */

static int	is_sorted(t_stack **stack_ab)
{
	t_stack	*temp;

	temp = *stack_ab;
	while (temp->next != NULL)
	{
		if (temp->index < temp->next->index)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

/**
 * @brief The function checks if elements' binary indexes are 0 or 1.
 * If the given binary is 0 it leaves the index to stack else pushes 
 * it to stack a.
 * 
 * @param sa Stack a
 * @param sb Stack b
 * @param i running index
 * @param max_b max bits in elements index.
 */

static void	check_and_push(t_stack **sa, t_stack **sb, int i, int max_b)
{
	t_stack	*temp;
	int		count;

	temp = *sb;
	count = ft_stacksize(temp);
	if (i < max_b - 1)
	{
		while (count > 0)
		{
			if (((temp->index >> (i + 1)) & 1) == 1)
				push_ab(sb, sa, 'a');
			else
				rotate_ab(sb, 'b');
			temp = *sb;
			count--;
		}
	}
	else
	{
		while (ft_stacksize(temp) != 0)
		{
			push_ab(sb, sa, 'a');
			temp = *sb;
		}
	}
}

/**
 * @brief Function divides the stack A by the elements index bits.
 * If binary is 1 it stays at stack A if 0 pushed to stack B.
 * 
 * @param sa stack a
 * @param sb stack b
 * @param max_i maximum index, equals stack size
 * @param max_b maximum binary size to represent biggest index of elements. 
 */

static void	div_by_bits(t_stack **sa, t_stack **sb, int max_i, int max_b)
{
	t_stack	*temp;
	int		i;
	int		index;

	temp = *sa;
	index = 0;
	i = -1;
	while (i + 1 < max_b)
	{
		temp = *sa;
		max_i = ft_stacksize(temp);
		while (max_i > 0 && is_sorted(sa) == 0)
		{
			index = temp->index;
			if (((index >> (i + 1)) & 1) == 1)
				rotate_ab(sa, 'a');
			else
				push_ab(sa, sb, 'b');
			temp = *sa;
			max_i--;
		}
		i++;
		check_and_push(sa, sb, i, max_b);
	}
}

/**
 * @brief Sorts elements based on their indexs' binary digits by bucketing them
 * to stack a (binary 1) and stack b (binary 0).
 * 
 * @param stack_a 
 * @param stack_b 
 */

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		max_index;
	int		max_bits;

	max_bits = 0;
	temp = *stack_a;
	max_index = ft_stacksize(temp) - 1;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	div_by_bits(stack_a, stack_b, max_index, max_bits);
}
