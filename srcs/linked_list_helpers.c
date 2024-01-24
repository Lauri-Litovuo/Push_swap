/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:09:45 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/24 15:08:48 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(node));
	if (!node)
		return (0);
	node->next = 0;
	node->content = content;
	node->index = -1;
	return (node);
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*stack_ptr;

	stack_ptr = *stack;
	if (*stack == 0)
		*stack = new;
	else
	{
		while (stack_ptr->next != NULL)
		{
			stack_ptr = stack_ptr->next;
		}
		stack_ptr->next = new;
	}
}

int	ft_stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	count_elements(char *str)
{
	int		count;
	char	ch;

	count = 0;
	ch = 32;
	while (*str != '\0')
	{
		if (*str == ch)
			str++;
		else
		{
			while (*str != ch && *str != '\0')
			{
				str++;
			}
			count++;
		}
	}
	return (count);
}
