/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:13:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/11 13:56:13 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
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
	/*reverse_rot(&head);
	temp = head;
	ft_printf("\n\n", temp->content);
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}*/
	return (0);
}
