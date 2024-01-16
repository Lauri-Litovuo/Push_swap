/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:13:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/16 12:24:26 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = input_to_list(ac, av);
	if (!stack_a)
		exit (EXIT_FAILURE);
	temp = stack_a;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
	give_index(&stack_a);
	printf("ac: %d\n", ac);
	if (ac == 4 || ac == 3)
		sort_three(&stack_a);
	if (ac == 5)
		sort_four(&stack_a, &stack_b);
	if (ac == 6)
		sort_five(&stack_a, &stack_b);
	temp = stack_a;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
	temp = stack_b;
	while (temp != NULL)
	{
		ft_printf("stack b;%d\n", temp->content);
		temp = temp->next;
	}
	return (0);
}
