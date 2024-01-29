/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_validate_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:24:07 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/29 13:30:00 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

/**
 * @brief Checks if string array has only digits as elements
 * 
 * @param elem_list 
 * @param count 
 * @return int returns 1 if only digits, 0 if something else.
 */
static int	digit_check(char **elem_list, int count)
{
	int		validity;
	int		i;
	int		j;

	validity = 1;
	i = 0;
	j = 0;
	while (i < count)
	{
		while (elem_list[i][j] != '\0')
		{
			validity = ft_isdigit(elem_list[i][j]);
			if (validity == 0 && \
				(elem_list[i][j] != '-' && ft_isdigit(elem_list[i][j] != 1)))
				return (0);
			if (j > 11)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Checks if string array has any duplicates as elements.
 * 
 * @param elem_list 
 * @param count 
 * @return int returns 1 if does not have duplicates, 0 if does.
 */

static int	duplicate_check(char **elem_list, int count)
{
	int		i;
	int		len;
	int		k;
	int		validity;

	k = 0;
	while (k < count - 1)
	{
		i = k + 1;
		while (i < count)
		{
			if (ft_strlen(elem_list[k]) != ft_strlen(elem_list[i]))
				validity = 1;
			else
			{
				len = ft_strlen(elem_list[k]);
				validity = ft_strncmp(elem_list[k], elem_list[i], len);
				if (validity == 0)
					return (0);
			}
			i++;
		}
		k++;
	}
	return (1);
}

/**
 * @brief Checks if the string array elements are in sorted order from 
 * smallest to biggest.
 * 
 * @param elem_list 
 * @param count 
 * @return int returns 0 if sorted, 1 if not.
 */

static int	check_need(char **elem_list, int count)
{
	int		i;

	i = 0;
	while (i + 1 < count)
	{
		if (ft_atoi(elem_list[i]) < ft_atoi(elem_list[i + 1]))
			i++;
		else
			return (1);
	}
	return (-1);
}

/**
 * @brief Checks if given numbers are within the int min and max values.
 * 
 * @param elem_list 
 * @param count 
 * @return int returns 0 if not, 1 if between values.
 */

static int	check_int(char **elem_list, int count)
{
	int		num;
	char	**num_str;
	int		i;
	int		len;

	num = 0;
	i = 0;
	num_str = (char **) malloc((count + 1) * sizeof(char **));
	if (!num_str)
		return (0);
	while (i < count)
	{
		num = ft_atoi(elem_list[i]);
		num_str[i] = ft_itoa(num);
		len = ft_strlen(elem_list[i]);
		if (ft_strncmp(elem_list[i], num_str[i], len) != 0)
		{
			free_array(num_str, i);
			return (0);
		}
		else
			i++;
	}
	free_array(num_str, i - 1);
	return (1);
}

int	validate_input(char **elem_list, int count)
{
	int	validity;

	validity = 1;
	validity = digit_check(elem_list, count);
	if (validity == 0)
		return (0);
	validity = duplicate_check(elem_list, count);
	if (validity == 0)
		return (0);
	validity = check_int(elem_list, count);
	if (validity == 0)
		return (0);
	validity = check_need(elem_list, count);
	if (validity == -1)
		return (-1);
	return (1);
}
