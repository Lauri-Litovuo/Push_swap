/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_linklist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:53:33 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/29 13:21:39 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

void	free_array(char **array, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	invalid_handling(char **elem_list, int count, int validity)
{
	if (validity == 0)
		write(2, "Error\n", 6);
	free_array(elem_list, count);
	return ;
}

/**
 * @brief Creates a linked list stack from string array.
 * 
 * @param stack 
 * @param elem_list Given string array.
 * @param count Size of the element list.
 * @return t_stack* Returns pointer to the created stack.
 */

t_stack	*make_stack(t_stack	**stack, char **elem_list, int count)
{
	t_stack	*new_node;
	long	content;
	int		i;

	i = 0;
	stack = NULL;
	new_node = NULL;
	content = ft_atoi(elem_list[i]);
	new_node = ft_stacknew(content);
	stack = &new_node;
	if (!new_node)
		return (NULL);
	i++;
	while (i <= count)
	{
		content = ft_atoi(elem_list[i]);
		if (!new_node)
			return (NULL);
		ft_stackadd_back(stack, ft_stacknew(content));
		i++;
	}
	return (new_node);
}

/**
 * @brief Creates a string array from the arguments. 
 * 
 * @param av argument vectors
 * @param count argument count - 1
 * @return char** Created string array.
 */

static char	**make_array(char **av, int count)
{
	char	**elem_list;
	int		i;

	i = 0;
	elem_list = (char **) malloc((count + 1) * sizeof(char **));
	if (!elem_list)
		return (NULL);
	while (i < count)
	{
		elem_list[i] = ft_strdup(av[1 + i]);
		if (elem_list[i] == NULL)
		{
			free_array(elem_list, i);
			return (NULL);
		}
		i++;
	}
	elem_list[count] = 0;
	return (elem_list);
}


/**
 * @brief Creates a linked list stack from the user input arguments.
 * 
 * @param ac Argument count
 * @param av Argument vectors
 * @return t_stack* Created stack.
 */

t_stack	*input_to_list(int ac, char **av)
{
	t_stack	*stack_a;
	char	**elem_list;
	int		count;
	int		validity;

	stack_a = NULL;
	count = ac - 1;
	if (ac == 2)
	{
		elem_list = ft_split(av[1], 32);
		count = count_elements(av[1]);
	}
	else
		elem_list = make_array(av, count);
	if (elem_list == NULL)
		return (NULL);
	validity = validate_input(elem_list, count);
	if (validity != 1)
	{
		invalid_handling(elem_list, count, validity);
		return (NULL);
	}
	stack_a = make_stack(&stack_a, elem_list, count - 1);
	free_array(elem_list, count - 1);
	return (stack_a);
}
