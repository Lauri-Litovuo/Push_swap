/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:13:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/13 18:09:03 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

int	main(int ac, char **av)
{
	t_stack	*head;
	t_stack	*temp;

	if (ac < 2)
		return (0);
	head = NULL;
	head = NULL;
	head = input_to_list(ac, av);
	if (!head)
		exit (EXIT_FAILURE);
	temp = head;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
	return (0);
}
