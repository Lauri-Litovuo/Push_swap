/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:13:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/10 17:00:43 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/pushlib.h"

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*temp;

	if (ac < 2)
		return (0);
	stack = NULL;
	temp = NULL;
	stack = input_to_list(ac, av);
	temp = stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->content);
		temp = temp->next;
	}
	return (0);
}
