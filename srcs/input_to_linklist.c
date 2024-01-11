/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_linklist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:53:33 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/11 11:13:20 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"
#include "../libft/libft.h"

static void	free_array(char **array, int size)
{
	while (size >= 0)
	{
		free(array[size]);
		size--;
	}
	free(array);
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

t_stack	*make_stack(t_stack	**stack, char **elem_list, int count)
{
	t_stack	*new_node;
	int		content;
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

static char	**make_array(char **av, int count)
{
	char	**elem_list;
	int		i;

	i = 0;
	elem_list = (char **) malloc((count + 1) * sizeof(char **));
	if (! (elem_list))
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

t_stack	*input_to_list(int ac, char **av)
{
	t_stack	*stack_a;
	char	**elem_list;
	int		count;

	elem_list = NULL;
	stack_a = NULL;
	count = 0;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		elem_list = ft_split(av[1], 32);
		count = count_elements(av[1]);
	}
	else
	{
		count = ac - 1;
		elem_list = make_array(av, count);
	}
	stack_a = make_stack(&stack_a, elem_list, count - 1);
	free_array(elem_list, count - 1);
	return (stack_a);
}