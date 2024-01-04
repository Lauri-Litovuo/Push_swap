/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:13:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/04 15:24:34 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../incl/pushlib.h"

int	main(void)
{
	t_stack	**stack;
	int		i;
	t_stack	**new;

	*stack = ft_stacknew(5);
	*new = ft_stacknew(4);
	ft_stackadd_front(stack, new);
	*new = ft_stacknew(3);
	ft_stackadd_front(stack, new);
	*new = ft_stacknew(2);
	ft_stackadd_front(stack, new);
	*new = ft_stacknew(1);
	ft_stackadd_front(stack, new);
	
}
