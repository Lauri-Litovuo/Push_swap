/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_number_generator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:33:06 by llitovuo          #+#    #+#             */
/*   Updated: 2024/01/31 17:02:26 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int		num_count;
	int		i;
	time_t	t;

	i = 0;
	printf("Input how many random numbers you want:\n");
	scanf("%d", &num_count);
	srand(time(&t));
	while (i < num_count)
	{
		printf("%d ", (2 * rand() - rand()) % 32767);
		i++;
	}
	printf("\n");
	return (0);
}