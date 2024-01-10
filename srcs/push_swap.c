/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:13:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/10 09:58:35 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../incl/pushlib.h"

static t_stack	*make_a_stack(char **given_list, int ac)
{
	t_stack	**stack;
	t_stack	**new_node;
	int		content;

	content = ft_atoi(given_list[ac]);
	*stack = ft_stacknew(content);
	if (!stack)
		return (0);
	ac--;
	while (ac > 1)
	{
		content = ft_atoi(given_list[ac]);
		*new_node = ft_stacknew(content);
		if (!new_node)
			return (0);
		ft_stackadd_front(stack, new_node);
	}
	return (*stack);
}


int	main(int ac, char **av)
{
	t_stack	**stack;
	t_stack	*temp;

	*stack = make_a_stack(av, ac);
	temp = *stack;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
}
