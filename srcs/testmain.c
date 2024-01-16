/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:36:24 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/16 10:09:35 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct t_stack {
    int content;
	int index;
    struct t_stack* next;
};

void	push_ab(struct t_stack **stack_from, struct t_stack **stack_to, char ch)
{
	struct t_stack	*pushed;

	if (*stack_from == NULL)
		return ;
	pushed = *stack_to;
	*stack_to = pushed->next;
	pushed->next = *stack_from;
	*stack_from = pushed;
	ft_printf("p%c", ch);
}

void	print_stack(struct t_stack *head)
{
	while (!head)
	{
		printf("%d\n", head->content);
		head = head->next;
	}
}

int	main() {

    struct t_stack* list1;
	struct t_stack* list2;
	
	list2 = NULL;
	list1 = (struct t_stack*)malloc(sizeof(struct t_stack));
    list1->content = 1;
	list1->index = -1;
    list1->next = (struct t_stack*)malloc(sizeof(struct t_stack));
    list1->next->content = 2;
	list1->next->index = -1;
    list1->next->next = (struct t_stack*)malloc(sizeof(struct t_stack));
    list1->next->next->content = 3;
	list1->next->next->index = -1;
    list1->next->next->next = (struct t_stack*)malloc(sizeof(struct t_stack));
    list1->next->next->next->content = 4;
	list1->next->next->next->index = -1;
    list1->next->next->next->next = NULL;

	print_stack(list1);
	push_ab(&list1, &list2, 'b');
	print_stack(list1);
	print_stack(list2);
	return (0);
}
