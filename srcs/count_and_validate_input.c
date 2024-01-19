/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_validate_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:24:07 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/19 15:25:31 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pushlib.h"

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
			if (validity == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
	validity = check_need(elem_list, count);
	if (validity == -1)
		return (-1);
	return (1);
}
