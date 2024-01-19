/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:36:24 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/19 14:33:04 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct t_stack {
    int content;
	int index;
    struct t_stack* next;
};

void	ft_stackadd_back(struct t_stack **stack, struct t_stack *new)
{
	struct t_stack	*stack_ptr;

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
void	rotate_ab(struct t_stack **stack, char ch)
{
	struct t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	ft_stackadd_back(stack, *stack);
	*stack = temp->next;
	temp->next = NULL;
	if (ch == 'a' || ch == 'b')
		printf("r%c\n", ch);
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

    struct t_stack	*list1;
	struct t_stack	*list2;
	struct t_stack *temp;

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

	temp = list1;
	while (temp != NULL)
	{
		printf("%d\n", temp->content);
		temp = temp->next;
	}
	rotate_ab(&list1, 'a');
	temp = list1;
	while (temp != NULL)
	{
		printf("%d\n", temp->content);
		temp = temp->next;
	}
	return (0);
}

	/*temp = stack_a;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}*/

/*void	print_binary(int dec_number)
{
	int binary_num = 0;
	int	i = 1;
	int	remainder;

	while (dec_number != 0)
	{
		remainder = dec_number % 2;
		dec_number /= 2;
		binary_num += remainder * i;
		i *= 10;
	}
	printf("Binary number: %d\n", binary_num);
}*/

/*static int	check_indexs(t_stack *node, t_stack *next_node)
{
	int	sorted;

	sorted = 1;
	while (!next_node)
	{
		if (node->index < next_node->index)
		{
			node = node->next;
			next_node = next_node->next;
		}
		else
		{
			sorted = 0;
			break ;
		}
	}
	return (sorted);
}*/

/*	temp = *stack_a;
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
	temp = *stack_a;
	while (temp != NULL) //		
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
	temp = *stack_b;
	while (temp != NULL)
	{
		ft_printf("stack b;%d\n", temp->content);
		temp = temp->next;
	} */
	
		/*temp = stack_a;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}*/
//index print
	/*	while (temp != NULL)
	{
		ft_printf("indexs:%d\n", temp->index);
		temp = temp->next;
	}*/