/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:13:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/23 14:32:30 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

void	free_stack(t_stack *stack_ab)
{
	t_stack	*temp;

	temp = NULL;
	while (stack_ab != NULL)
	{
		temp = stack_ab;
		stack_ab = stack_ab->next;
		free(temp);
	}
}

void	sorter_guider(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (count > 5)
		radix_sort(stack_a, stack_b);
	else if (count == 5)
		sort_five(stack_a, stack_b);
	else if (count == 4)
		sort_four(stack_a, stack_b);
	else if (count == 3 || count == 2)
		sort_three(stack_a);
	else
		return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;

	count = 0;
	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = input_to_list(ac, av);
	if (!stack_a)
	{
		free(stack_a);
		exit (EXIT_FAILURE);
	}
	give_index(&stack_a);
	count = ft_stacksize(stack_a);
	sorter_guider(&stack_a, &stack_b, count);
	free_stack(stack_a);
	free_stack(stack_b);
	exit (EXIT_SUCCESS);
}
